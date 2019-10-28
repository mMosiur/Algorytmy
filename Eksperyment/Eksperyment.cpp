#include <iostream>
#include <string>

typedef unsigned int uint;
typedef unsigned short ushort;

struct Scientist {
	std::string first_name;
	std::string last_name;
	ushort sci_val{ 0 };
	Scientist* next = nullptr;
};

class Group {
	Scientist* head = nullptr;
	Scientist* tail = nullptr;
	ushort size = 0;
	ushort min_sci_val = 1000;
	ushort max_sci_val = 0;
	uint sum_sci_val = 0;
public:
	~Group() {
		Scientist* pos = head;
		while (pos != nullptr) {
			Scientist* tmp = pos;
			pos = pos->next;
			delete tmp;
		}
	}
	bool empty() {
		return size == 0;
	}
	Scientist* front() {
		return head;
	}
	Scientist* back() {
		return tail;
	}
	void push(Scientist* scientist) {
		scientist->next = nullptr;
		if (size == 0) {
			head = tail = scientist;
			max_sci_val = min_sci_val = scientist->sci_val;
		} else {
			tail->next = scientist;
			tail = scientist;
			if (scientist->sci_val > max_sci_val) max_sci_val = scientist->sci_val;
			else if (scientist->sci_val < min_sci_val) min_sci_val = scientist->sci_val;
		}
		sum_sci_val += scientist->sci_val;
		size++;
	}
	Scientist* pop() {
		if (size == 0) return nullptr;
		Scientist* popped;
		if (size == 1) {
			popped = head;
			head = nullptr;
			min_sci_val = 1000;
			max_sci_val = sum_sci_val = 0;
		} else {
			popped = head;
			head = head->next;
			if (popped->sci_val == max_sci_val) {
				max_sci_val = head->sci_val;
				for (Scientist* pos = head->next; pos != nullptr; pos = pos->next) {
					if (pos->sci_val > max_sci_val) max_sci_val = pos->sci_val;
				}
			} else if (popped->sci_val == min_sci_val) {
				min_sci_val = head->sci_val;
				for (Scientist* pos = head->next; pos != nullptr; pos = pos->next) {
					if (pos->sci_val < min_sci_val) min_sci_val = pos->sci_val;
				}
			}
			sum_sci_val -= popped->sci_val;
		}
		size--;
		return popped;
	}
	ushort sci_diff() {
		return max_sci_val - min_sci_val;
	}
	uint sci_sum() {
		return sum_sci_val;
	}
	void display() {
		for (Scientist* pos = head; pos != nullptr; pos = pos->next) {
			std::cout << pos->first_name << " " << pos->last_name << std::endl;
		}
	}
};

class Table {
	Group group_1;
	Group group_2;
	uint table_size;
	ushort max_diff;
public:
	Table(uint n, ushort v) : table_size(n), max_diff(v) {
		for (int i = table_size / 2; i > 0; i--) {
			Scientist* scientist = new Scientist;
			std::cin >> scientist->first_name >> scientist->last_name >> scientist->sci_val;
			group_1.push(scientist);
		}
		for (int i = table_size / 2; i > 0; i--) {
			Scientist* scientist = new Scientist;
			std::cin >> scientist->first_name >> scientist->last_name >> scientist->sci_val;
			group_2.push(scientist);
		}
	}
	void shift_groups(ushort nof_pos_shifted = 1) {
		while (nof_pos_shifted-- > 0) {
			group_1.push(group_2.pop());
			group_2.push(group_1.pop());
		}
	}
	bool is_valid() {
		return group_1.sci_diff() <= max_diff && group_2.sci_diff() <= max_diff;
	}
	uint sci_val_sum_diff() {
		return abs((int)group_1.sci_sum() - (int)group_1.sci_sum());
	}
	void display() {
		group_2.display();
		std::cout << " " << std::endl;
		group_1.display();
	}
};

int main() {
	uint n; // Iloœæ naukowców
	ushort v; // Maksymalna ró¿nica zdolnoœci naukowych w zespole

	std::cin >> n >> v;

	Table table(n, v);

	uint min_sci_val_sum_diff = 1000;
	ushort index = 0;
	for (int i = 0; i < n / 2; i++) {
		if (table.is_valid()) {
			if (min_sci_val_sum_diff > table.sci_val_sum_diff()) {
				min_sci_val_sum_diff = table.sci_val_sum_diff();
				index = i;
			}
		}
		table.shift_groups();
		/*if (first_half.sci_diff() <= v && second_half.sci_diff() <= v) {
			uint sum_diff = abs((int)first_half.sci_sum() - (int)second_half.sci_sum());
			if (min_sum_diff > sum_diff) {
				if (sum_diff == 0) {
					for (Scientist* pos = first_half.front(); pos != nullptr; pos = pos->next) {
						std::cout << pos->first_name << " " << pos->last_name << std::endl;
					}
					std::cout << " " << std::endl;
					for (Scientist* pos = second_half.front(); pos != nullptr; pos = pos->next) {
						std::cout << pos->first_name << " " << pos->last_name << std::endl;
					}
					return 0;
				}
				min_sum_diff = sum_diff;
				index = i;
			}
		}
		first_half.push(second_half.pop());
		second_half.push(first_half.pop());*/
	}

	if (min_sci_val_sum_diff == 1000) {
		std::cout << "NIE" << std::endl;
		return 0;
	}

	table.shift_groups(index);

	table.display();

	return 0;
}