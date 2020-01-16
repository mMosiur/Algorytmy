#include <iostream>
#include <exception>

typedef unsigned short ushort;
typedef unsigned int uint;

// Struktura reprezentuj�ca pa�stwo
struct Nation {
	ushort number; // Numer pa�stwa przypisany ze wzgl�d�w konspiracyjnych
	uint priority; // Wsp�czynnik przypisany danemu pa�stwu

	// Operator por�wnuj�cy pa�stwa wzgl�dem ich wsp�czynik�w
	bool operator <(const Nation& other) const {
		return this->priority < other.priority;
	}
};

// Klasa kopca pa�stw
class NationHeap {
	ushort nof_nations; // Liczba pa�st w kopcu
	Nation* nations; // Tablica pa�stw
	ushort indexes[1000]; // Tablica indeks�w pa�stw

	// Funkcja zamieniaj�ca miejscami dwa pa�stwa
	void swap(Nation& a, Nation& b) {
		std::swap(indexes[a.number], indexes[b.number]);
		std::swap(a, b);
	}

	// Funkcja zwracaj�da index rodzica elementu o danym indeksie
	ushort parent(ushort index) {
		index = (index - 1) / 2;
		return index;
	}

	// Funkcja zwracaj�da indeks lewego dziecka elementu o danym indeksie
	ushort left_child(ushort index) {
		index = index * 2 + 1;
		return index;
	}

	// Funkcja zwracaj�da indeks prawego dziecka elementu o danym indeksie
	ushort right_child(ushort index) {
		index = index * 2 + 2;
		return index;
	}

	// Funkcja przywracaj�ca w�asno�� kopca id�c w g�r� od elementu o danym indeksie, zwracaj�ca liczb� dokonanych zamian
	ushort HeapifyUp(ushort pos) {
		ushort nof_swaps = 0;
		while(pos != 0 && nations[parent(pos)] < nations[pos]) { // Dop�ki element ma rodzica i rodzic jest mniejszy od elementu
			// Dokonaj zamiany
			swap(nations[parent(pos)], nations[pos]);
			nof_swaps++;
			pos = parent(pos);
		}
		return nof_swaps;
	}

	// Funkcja przywracaj�ca w�asno�� kopca id�c w d� od elementu o danym indeksie, zwracaj�ca liczb� dokonanych zamian
	ushort HeapifyDown(ushort pos) {
		ushort nof_swaps = 0;
		while(left_child(pos) < nof_nations) { // Dop�ki element ma lewe dziecko <=> ma dzieci
			if(right_child(pos) < nof_nations) { // Element ma prawe dziecko
				if(nations[left_child(pos)] < nations[right_child(pos)]) { // Lewe dziecko jest mniejsze ni� prawe dziecko
					if(nations[pos] < nations[right_child(pos)]) { // Element jest mnieszy ni� jego prawe dziecko
						// Dokonaj zamiany
						swap(nations[right_child(pos)], nations[pos]);
						nof_swaps++;
						pos = right_child(pos);
					} else break; // Element jest wi�kszy lub r�wny prawemu dziecku, wyjd� z p�tli
				} else { // Lewe dziecko jest wi�ksze lub r�wne prawemu dziecku
					if(nations[pos] < nations[left_child(pos)]) { // Element jest mniejszy ni� jego lewe dziecko
						// Dokonaj zamiany
						swap(nations[left_child(pos)], nations[pos]);
						nof_swaps++;
						pos = left_child(pos);
					} else break; // Element jest wi�kszy lub r�wny lewemu dziecku, wyjd� z p�tli
				}
			} else { // Element nie ma prawego dziecka
				if(nations[pos] < nations[left_child(pos)]) { // Element jest mniejszy ni� jego prawe dziecko
					// Dokonaj zamiany
					swap(nations[pos], nations[left_child(pos)]);
					nof_swaps++;
					pos = left_child(pos);
				}
				break; // Wyjd� z p�tli (brak prawego dziecka oznacza �e lewe dziecko nie b�dzie mia�o dzieci)
			}
		}
		return nof_swaps;
	}

public:

	// Konstruktor przyjmuj�cy ilo�� pa�stw i wczytuj�cy je
	NationHeap(ushort nof_nations) : nof_nations(nof_nations), nations(new Nation[nof_nations]) {
		for(ushort i = 0; i < nof_nations; i++) {
			std::cin >> nations[i].number >> nations[i].priority;
			indexes[nations[i].number] = i;
		}
	}

	// Funkcja przyjmuj�ca ilo�� modyfikacji do wykonania, wczytuj�ca dane o modyfikacjach oraz zwracaj�ca ilo�� wywo�anych zamian
	uint modify(uint nof_modifications) {
		uint nof_swaps = 0;
		for(uint i = 0; i < nof_modifications; i++) {
			ushort number;
			uint new_priority;
			std::cin >> number >> new_priority;
			int diff = new_priority - nations[indexes[number]].priority;
			if(diff > 0) { // Przesiewanie w g�r�
				nations[indexes[number]].priority = new_priority;
				nof_swaps += HeapifyUp(indexes[number]);
			} else if(diff < 0) { // Przesiewanie w d�
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