#include <iostream>
#include <vector>

typedef unsigned short ushort;
typedef unsigned int uint;

// Struktura reprezentuj¹ca pañstwo
struct Nation {
	uint number; // Numer pañstwa przypisany ze wzglêdów konspiracyjnych (0 - 10,000,000)
	uint priority; // Wspó³czynnik przypisany danemu pañstwu

	// Operator porównuj¹cy pañstwa wzglêdem ich wspó³czyników
	bool operator <(const Nation& other) const {
		return this->priority < other.priority;
	}
};

// Klasa reprezentuj¹ca system znajduj¹cy k-te pañstwo
class NationPicker {
	std::vector<Nation> nations; // Wektor wszystkich pañstw

	// Funkcja zwracaj¹ca k-te pañstwo pod wzglêdem jego wspó³czynnika miêdzy indeksami start oraz end (dla zer funkcja zacznie dla ca³ego wektora pañstw)
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

	// Konstruktor przyjmuj¹cy iloœæ pañstw i wczytuj¹cy ich dane
	NationPicker(uint nof_nations) : nations(std::vector<Nation>(nof_nations)){
		for(auto& nation : nations) {
			std::cin >> nation.number >> nation.priority;
		}
	}

	// Funkcja przyjmuj¹ca liczbê zapytañ do systemu, wczytuj¹ca te zapytania a nastêpnie wypisuj¹cia rezultaty dla kolejnych zapytañ
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