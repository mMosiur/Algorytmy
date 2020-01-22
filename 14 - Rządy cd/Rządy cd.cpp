#include <iostream>
#include <vector>

typedef unsigned short ushort;
typedef unsigned int uint;

// Struktura reprezentuj�ca pa�stwo
struct Nation {
	uint number; // Numer pa�stwa przypisany ze wzgl�d�w konspiracyjnych (0 - 10,000,000)
	uint priority; // Wsp�czynnik przypisany danemu pa�stwu

	// Operator por�wnuj�cy pa�stwa wzgl�dem ich wsp�czynik�w
	bool operator <(const Nation& other) const {
		return this->priority < other.priority;
	}
};

// Klasa reprezentuj�ca system znajduj�cy k-te pa�stwo
class NationPicker {
	std::vector<Nation> nations; // Wektor wszystkich pa�stw

	// Funkcja zwracaj�ca k-te pa�stwo pod wzgl�dem jego wsp�czynnika mi�dzy indeksami start oraz end (dla zer funkcja zacznie dla ca�ego wektora pa�stw)
	Nation& kth_nation(uint k, uint start = 0, uint end = 0) { 
		if(end == 0) end = nations.size();
		uint pivot = start + (rand() % (end-start));
		std::swap(nations[pivot], nations[end - 1]);
		pivot = end - 1;
		uint smaller_end = start, equal_end = start;
		for(uint bigger_end = start; bigger_end < pivot; bigger_end++) {
			if(nations[bigger_end] < nations[pivot]) {
				std::swap(nations[bigger_end], nations[equal_end]);
				std::swap(nations[equal_end], nations[smaller_end]);
				smaller_end++;
				equal_end++;
			} else if(!(nations[pivot] < nations[bigger_end])) { // ==
				std::swap(nations[bigger_end], nations[equal_end]);
				equal_end++;
			}
		}
		std::swap(nations[pivot], nations[equal_end]);
		equal_end++;
		uint nof_smaller = smaller_end - start;
		uint nof_equal = equal_end - smaller_end;
		if(k < nof_smaller) return kth_nation(k, start, smaller_end);
		if(k >= nof_smaller + nof_equal) return kth_nation(k - (nof_smaller + nof_equal), equal_end, end);
		uint smallest_index = smaller_end;
		for(uint i = smaller_end; i < equal_end; i++) {
			if(nations[i].number < nations[smallest_index].number) smallest_index = i;
		}
		return nations[smallest_index];
	}

public:

	// Konstruktor przyjmuj�cy ilo�� pa�stw i wczytuj�cy ich dane
	NationPicker(uint nof_nations) : nations(std::vector<Nation>(nof_nations)){
		for(auto& nation : nations) {
			std::cin >> nation.number >> nation.priority;
		}
	}

	// Funkcja przyjmuj�ca liczb� zapyta� do systemu, wczytuj�ca te zapytania a nast�pnie wypisuj�cia rezultaty dla kolejnych zapyta�
	void find_nations(ushort nof_queries) {
		for(ushort i = 0; i < nof_queries; i++) {
			uint k;
			std::cin >> k;
			std::cout << kth_nation(k - 1).number << std::endl;
		}
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	uint n;
	std::cin >> n;

	NationPicker picker(n);

	uint m;
	std::cin >> m;

	picker.find_nations(m);

	return 0;
}