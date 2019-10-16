#include <iostream>
#include <string>

struct Node {
	Node* prev;
	std::string word;
	int shift;
	Node* next;
};

class LinkedList {
	Node* head = nullptr;
	unsigned short size = 0;
public:
	bool empty() {
		return size == 0;
	}
	Node* front() {
		return head;
	}
	void push_back(Node* node) {
		if (head == nullptr) {
			head = node;
			head->prev = head;
			head->next = head;
		} else {
			node->prev = head->prev;
			node->next = head;
			head->prev->next = node;
			head->prev = node;
		}
		size++;
	}
	void insert(Node* pos, Node* node) {
		if (pos == nullptr) {
			head = node;
			head->prev = head;
			head->next = head;
		} else {
			node->prev = pos->prev;
			node->next = pos;
			pos->prev->next = node;
			pos->prev = node;
			if (pos == head) head = node;
		}
		size++;
	}
	void erase(Node* pos) {
		if (head->next == head) {
			delete head;
			head = nullptr;
		} else {
			pos->prev->next = pos->next;
			pos->next->prev = pos->prev;
			if (pos == head) head = pos->next;
			delete pos;
		}
		size--;
	}
	Node* shift(Node* pos, int shift) {
		if (size == 0) return nullptr;
		if (size == 1) return head;
		shift %= size;
		if (shift < (-size / 2)) shift += size;
		else if (shift > (size / 2)) shift -= size;
		if (shift < 0) {
			while (shift++ < 0) pos = pos->prev;
		} else {
			while (shift-- > 0) pos = pos->next;
		}
		return pos;
		
	}
};

int main() {
	unsigned short n; // rozmiar listy s³ów
	unsigned short s; // numer s³owa startowego
	std::cin >> n >> s;

	LinkedList list;

	// Wczytanie wszytkich s³ów
	while (n-- > 0) {
		Node* node = new Node;
		std::cin >> node->word >> node->shift;
		list.push_back(node);
	}

	std::cin >> n; // rozmiar listy rezerwowej

	Node* pos = list.front();
	while (s-- > 0) pos = pos->next;

	std::string result = "";
	while (!list.empty()) {
		int shift = pos->shift;
		if (shift == 0) {
			Node* node = new Node;
			std::cin >> node->word >> node->shift >> pos->shift;
			list.insert(pos, node);
			pos = list.shift(pos, pos->shift);
		} else {
			result += pos->word + " ";
			if (shift > 0) {
				pos = pos->prev;
				list.erase(pos->next);
			} else {
				pos = pos->next;
				list.erase(pos->prev);
			}
			pos = list.shift(pos, shift);
		}
	}

	std::cout << result;

	return 0;
}