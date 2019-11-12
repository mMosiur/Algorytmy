#include <iostream>
#include <string>

typedef unsigned int uint;
typedef unsigned short ushort;


struct Scientist {
	std::string name; // Imiê i nazwisko
	ushort sci_val = 0; // Zdolnoœæ naukowa
	Scientist* next = nullptr;
};

class Group {
	Scientist* head = nullptr;
	Scientist* tail = nullptr;
	ushort size = 0; // Wielkoœæ grupy
	ushort min_sci_val = 1000; // Minimalna wartoœæ zdolnoœci naukowej w grupie
	ushort max_sci_val = 0; // Maksymalna wartoœæ zdolnoœci naukowej w grupie
	uint sum_sci_val = 0; // Suma zdolnoœci naukowych w grupie
public:

	// Destruktor
	~Group() {
		Scientist* pos = head;
		while (pos != nullptr) {
			Scientist* tmp = pos;
			pos = pos->next;
			delete tmp;
		}
	}

	// Zwraca pierwszego naukowca w grupie
	Scientist* front() {
		return head;
	}

	// Zwraca ostatniego naukowca w grupie
	Scientist* back() {
		return tail;
	}

	// Dodaje naukowca do grupy
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

	// Usuwa naukowca z grupy i go zwraca
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

	// Ró¿nica miêdzy najlepszym i najgorszym naukowcem
	ushort sci_val_diff() {
		return max_sci_val - min_sci_val;
	}

	// Suma zdolnoœci naukowych w grupie
	uint sci_val_sum() {
		return sum_sci_val;
	}

	// Wyœwietla osoby w grupie
	void display() {
		for (Scientist* pos = head; pos != nullptr; pos = pos->next) {
			std::cout << pos->name << std::endl;
		}
	}
};

class Table {
	Group group_1; // Grupa pierwsza
	Group group_2; // Grupa druga
	uint size; // Iloœæ naukowców przy stole
	ushort max_diff; // Maksymalna dopuszczalna rónica zdolnoœci naukowych w grupie
public:

	// Konstruktor
	Table(uint size, ushort max_diff) : size(size), max_diff(max_diff) {
		std::string tmp;
		for (ushort i = size / 2; i > 0; i--) {
			Scientist* scientist = new Scientist;
			std::cin >> scientist->name >> tmp >> scientist->sci_val;
			scientist->name += " " + tmp;
			group_1.push(scientist);
		}
		for (ushort i = size / 2; i > 0; i--) {
			Scientist* scientist = new Scientist;
			std::cin >> scientist->name >> tmp >> scientist->sci_val;
			scientist->name += " " + tmp;
			group_2.push(scientist);
		}
	}

	// Przesuwa podzia³ na grupy o jedn¹ osobê
	void shift_groups(ushort shift = 1) {
		while (shift-- > 0) {
			group_1.push(group_2.pop());
			group_2.push(group_1.pop());
		}
	}

	// Sprawdza czy ró¿nice zdolnoœci naukowych w grupach s¹ poni¿ej maksimum
	bool is_valid() {
		return group_1.sci_val_diff() <= max_diff && group_2.sci_val_diff() <= max_diff;
	}

	// Zwraca ró¿nicê sum zdolnoœci naukowych w dwóch grupach
	uint sci_val_sum_diff() {
		return abs((int)group_1.sci_val_sum() - (int)group_2.sci_val_sum());
	}

	// Wyœwietla grupy w ze spacj¹ pomiêdzy, najpierw grupa_2 dla reversed = true
	void display(bool reversed = false) {
		if (reversed) {
			group_2.display();
			std::cout << " " << std::endl;
			group_1.display();
		} else {
			group_1.display();
			std::cout << " " << std::endl;
			group_2.display();
		}
	}
};

int main() {
	uint n; // Iloœæ naukowców
	ushort v; // Maksymalna rónica zdolnoœci naukowych w zespole

	std::cin >> n >> v;

	Table table(n, v);

	uint min_sci_val_sum_diff = 50000000;
	ushort index = 0;
	for (ushort i = 0; i < n / 2; i++) {
		if (table.is_valid()) {
			uint sci_val_sum_diff = table.sci_val_sum_diff();
			if (min_sci_val_sum_diff > sci_val_sum_diff) {
				if (sci_val_sum_diff == 0) {
					table.display();
					return 0;
				}
				min_sci_val_sum_diff = sci_val_sum_diff;
				index = i;
			}
		}
		table.shift_groups();
	}

	if (min_sci_val_sum_diff == 50000000) {
		std::cout << "NIE" << std::endl;
		return 0;
	}

	table.shift_groups(index);

	table.display(true);

	return 0;
}