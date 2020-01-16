#include <iostream>
#include <exception>

typedef unsigned short ushort;
typedef unsigned int uint;

// Struktura reprezentuj¹ca pañstwo
struct Nation {
	ushort number; // Numer pañstwa przypisany ze wzglêdów konspiracyjnych
	uint priority; // Wspó³czynnik przypisany danemu pañstwu

	// Operator porównuj¹cy pañstwa wzglêdem ich wspó³czyników
	bool operator <(const Nation& other) const {
		return this->priority < other.priority;
	}
};

// Klasa kopca pañstw
class NationHeap {
	ushort nof_nations; // Liczba pañst w kopcu
	Nation* nations; // Tablica pañstw
	ushort indexes[1000]; // Tablica indeksów pañstw

	// Funkcja zamieniaj¹ca miejscami dwa pañstwa
	void swap(Nation& a, Nation& b) {
		std::swap(indexes[a.number], indexes[b.number]);
		std::swap(a, b);
	}

	// Funkcja zwracaj¹da index rodzica elementu o danym indeksie
	ushort parent(ushort index) {
		index = (index - 1) / 2;
		return index;
	}

	// Funkcja zwracaj¹da indeks lewego dziecka elementu o danym indeksie
	ushort left_child(ushort index) {
		index = index * 2 + 1;
		return index;
	}

	// Funkcja zwracaj¹da indeks prawego dziecka elementu o danym indeksie
	ushort right_child(ushort index) {
		index = index * 2 + 2;
		return index;
	}

	// Funkcja przywracaj¹ca w³asnoœæ kopca id¹c w górê od elementu o danym indeksie, zwracaj¹ca liczbê dokonanych zamian
	ushort HeapifyUp(ushort pos) {
		ushort nof_swaps = 0;
		while(pos != 0 && nations[parent(pos)] < nations[pos]) { // Dopóki element ma rodzica i rodzic jest mniejszy od elementu
			// Dokonaj zamiany
			swap(nations[parent(pos)], nations[pos]);
			nof_swaps++;
			pos = parent(pos);
		}
		return nof_swaps;
	}

	// Funkcja przywracaj¹ca w³asnoœæ kopca id¹c w dó³ od elementu o danym indeksie, zwracaj¹ca liczbê dokonanych zamian
	ushort HeapifyDown(ushort pos) {
		ushort nof_swaps = 0;
		while(left_child(pos) < nof_nations) { // Dopóki element ma lewe dziecko <=> ma dzieci
			if(right_child(pos) < nof_nations) { // Element ma prawe dziecko
				if(nations[left_child(pos)] < nations[right_child(pos)]) { // Lewe dziecko jest mniejsze ni¿ prawe dziecko
					if(nations[pos] < nations[right_child(pos)]) { // Element jest mnieszy ni¿ jego prawe dziecko
						// Dokonaj zamiany
						swap(nations[right_child(pos)], nations[pos]);
						nof_swaps++;
						pos = right_child(pos);
					} else break; // Element jest wiêkszy lub równy prawemu dziecku, wyjdŸ z pêtli
				} else { // Lewe dziecko jest wiêksze lub równe prawemu dziecku
					if(nations[pos] < nations[left_child(pos)]) { // Element jest mniejszy ni¿ jego lewe dziecko
						// Dokonaj zamiany
						swap(nations[left_child(pos)], nations[pos]);
						nof_swaps++;
						pos = left_child(pos);
					} else break; // Element jest wiêkszy lub równy lewemu dziecku, wyjdŸ z pêtli
				}
			} else { // Element nie ma prawego dziecka
				if(nations[pos] < nations[left_child(pos)]) { // Element jest mniejszy ni¿ jego prawe dziecko
					// Dokonaj zamiany
					swap(nations[pos], nations[left_child(pos)]);
					nof_swaps++;
					pos = left_child(pos);
				}
				break; // WyjdŸ z pêtli (brak prawego dziecka oznacza ¿e lewe dziecko nie bêdzie mia³o dzieci)
			}
		}
		return nof_swaps;
	}

public:

	// Konstruktor przyjmuj¹cy iloœæ pañstw i wczytuj¹cy je
	NationHeap(ushort nof_nations) : nof_nations(nof_nations), nations(new Nation[nof_nations]) {
		for(ushort i = 0; i < nof_nations; i++) {
			std::cin >> nations[i].number >> nations[i].priority;
			indexes[nations[i].number] = i;
		}
	}

	// Funkcja przyjmuj¹ca iloœæ modyfikacji do wykonania, wczytuj¹ca dane o modyfikacjach oraz zwracaj¹ca iloœæ wywo³anych zamian
	uint modify(uint nof_modifications) {
		uint nof_swaps = 0;
		for(uint i = 0; i < nof_modifications; i++) {
			ushort number;
			uint new_priority;
			std::cin >> number >> new_priority;
			int diff = new_priority - nations[indexes[number]].priority;
			if(diff > 0) { // Przesiewanie w górê
				nations[indexes[number]].priority = new_priority;
				nof_swaps += HeapifyUp(indexes[number]);
			} else if(diff < 0) { // Przesiewanie w dó³
				nations[indexes[number]].priority = new_priority;
				nof_swaps += HeapifyDown(indexes[number]);
			}
		}
		return nof_swaps;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	ushort n;
	std::cin >> n;

	NationHeap heap(n);

	uint m;
	std::cin >> m;

	std::cout << heap.modify(m) << std::endl;

	return 0;
}