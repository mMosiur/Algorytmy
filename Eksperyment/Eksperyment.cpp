#include <iostream>
#include <string>

typedef unsigned int uint;
typedef unsigned short ushort;

struct Scientist {
	Scientist* prev = nullptr;
	std::string f; // Imiê
	std::string s; // Nazwisko
	ushort i = 0; // Zdolnoœæ naukowa
	Scientist* next = nullptr;
};

class Queue {
	Scientist* head = new Scientist;
	uint n = 0;
	ushort max_i = 1;
	ushort min_i = 1000;
	uint sum = 0;
public:
	Queue() {
		head->prev = head->next = head;
	}
	bool empty() {
		return n == 0;
	}
	uint size() {
		return n;
	}
	Scientist* front() {
		return head->next;
	}
	Scientist* back() {
		return head->prev;
	}
	void push(Scientist* scientist) {
		scientist->prev = head->prev;
		scientist->next = head;
		head->prev->next = scientist;
		head->prev = scientist;
		n++;
		sum += scientist->i;
		if (scientist->i > max_i) max_i = scientist->i;
		else if (scientist->i < min_i) min_i = scientist->i;
	}
	Scientist* pop() {
		if (n == 0) return nullptr;
		Scientist* popped = head->next;
		head->next = head->next->next;
		head->next->prev = head;
		n--;
		sum -= popped->i;
		if (popped->i == max_i) {
			max_i = 1;
			for (Scientist* pos = head->next; pos != head; pos = pos->next) {
				if (pos->i > max_i) max_i = pos->i;
			}
		} else if (popped->i == min_i) {
			min_i = 1000;
			for (Scientist* pos = head->next; pos != head; pos = pos->next) {
				if (pos->i < min_i) min_i = pos->i;
			}
		}
		return popped;
	}
	float avg() {
		return (float)sum / n;
	}
	uint diff() {
		return max_i - min_i;
	}
};

int main() {
	uint n; // Iloœæ naukowców
	ushort v; // Maksymalna ró¿nica zdolnoœci naukowych w zespole

	std::cin >> n >> v;

	Queue first_half;
	for (int i = n / 2; i > 0; i--) {
		Scientist* scientist = new Scientist;
		std::cin >> scientist->f >> scientist->s >> scientist->i;
		first_half.push(scientist);
	}
	Queue second_half;
	for (int i = n / 2; i > 0; i--) {
		Scientist* scientist = new Scientist;
		std::cin >> scientist->f >> scientist->s >> scientist->i;
		second_half.push(scientist);
	}

	float min_avg_diff = 1000.0;
	uint min_diff_sum = 0;
	ushort index = 0;
	for (int i = 0; i < n / 2; i++) {
		if (first_half.diff() <= v && second_half.diff() <= v) {
			float avg_diff = abs(first_half.avg() - second_half.avg());
			if (min_avg_diff > avg_diff || (min_avg_diff == avg_diff && min_diff_sum > first_half.diff() + second_half.diff())) {
				min_avg_diff = avg_diff;
				min_diff_sum = first_half.diff() + second_half.diff();
				index = i;
			}
		}
		first_half.push(second_half.pop());
		second_half.push(first_half.pop());
	}

	while (index-- > 0) {
		first_half.push(second_half.pop());
		second_half.push(first_half.pop());
	}

	for (Scientist* pos = second_half.front(); pos != second_half.back()->next; pos = pos->next) {
		std::cout << pos->f << " " << pos->s << std::endl;
	}
	std::cout << " " << std::endl;
	for (Scientist* pos = first_half.front(); pos != first_half.back()->next; pos = pos->next) {
		std::cout << pos->f << " " << pos->s << std::endl;
	}

	return 0;
}
