#include <iostream>

typedef unsigned short ushort;
typedef unsigned int uint;

struct Nation {
	ushort number;
	uint factor;

	bool operator <(const Nation& other) const {
		return this->factor < other.factor;
	}
};

class Heap {
	ushort nof_nations;
	Nation* nations;
	ushort indexes[1000];

	void swap(Nation& a, Nation& b) {
		std::swap(indexes[a.number - 1], indexes[b.number - 1]);
		std::swap(a, b);
	}

	Nation& nation(ushort number) {
		return nations[indexes[number - 1]];
	}

	ushort parent(ushort index) {
		return (index - 1) / 2;
	}

	Nation& parent(Nation& nation) {
		ushort index = indexes[nation.number - 1];
		index = parent(index);
		return nations[index];
	}

	ushort left_child(ushort index) {
		return index * 2 + 1;
	}

	Nation& left_child(Nation& nation) {
		ushort index = indexes[nation.number - 1];
		index = left_child(index);
		return nations[index];
	}

	ushort right_child(ushort index) {
		return index * 2 + 2;
	}

	Nation& right_child(Nation& nation) {
		ushort index = indexes[nation.number - 1];
		index = right_child(index);
		return nations[index];
	}

public:

	Heap(ushort nof_nations) : nof_nations(nof_nations), nations(new Nation[nof_nations]) {
		for(ushort i = 0; i < nof_nations; i++) {
			std::cin >> nations[i].number >> nations[i].factor;
			indexes[nations[i].number - 1] = i;

			for(ushort pos = i; pos != 0 && parent(nations[pos]) < nations[pos]; pos = parent(pos)) {
				swap(parent(nations[pos]), nations[pos]);
			}

		}
	}

	uint modify(ushort nof_modifications) {
		uint result = 0;
		for(uint i = 0; i < nof_modifications; i++) {
			ushort number;
			uint new_factor;
			std::cin >> number >> new_factor;
			int diff = new_factor - nation(number).factor;
			if(diff > 0) {
				nation(number).factor = new_factor;
				for(ushort pos = indexes[number - 1]; pos != 0 && parent(nations[pos]) < nations[pos]; pos = parent(pos)) {
					swap(parent(nations[pos]), nations[pos]);
					result++;
				}
			} else if(diff < 0) {
				ushort pos = indexes[number - 1];
				while(left_child(pos) < nof_nations) {
					nation(number).factor = new_factor;
					if(right_child(pos) < nof_nations && left_child(nation(number)) < right_child(nation(number))) { // swap with right
						if(nation(number) < right_child(nation(number))) {
							swap(right_child(nation(number)), nation(number));
							result++;
							pos = right_child(pos);
						}
					} else { // swap with left
						if(nation(number) < left_child(nation(number))) {
							swap(left_child(nation(number)), nation(number));
							result++;
							pos = left_child(pos);
						}
					}
				}
			}
		}
		return result;
	}

	void print() {
		for(ushort i = 0; i < nof_nations; i++) {
			std::cout << i << " > " << nations[i].number << " " << nations[i].factor << std::endl;
		}
	}

};

int main() {
	ushort n;
	std::cin >> n;

	Heap heap(n);

	uint m;
	std::cin >> m;

	std::cout << heap.modify(m) << std::endl;

	return 0;
}