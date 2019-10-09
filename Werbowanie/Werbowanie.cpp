#include <iostream>
#include <string>

typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long int ullint;

struct person {
	std::string name;
	ullint time;
	bool operator > (const person& other) const {
		if (this->time < other.time) return true;
		else if (this->time == other.time && this->name > other.name) return true;
		return false;
	}
};

int main() {
	ushort t;
	std::cin >> t;
	while (t-- > 0) { // Przejœcie po wszystkich zestawach danych

		/* Wczytanie danych */

		ushort n; // Liczba nazwisk
		ushort p; // Liczna nazwisk do wyœwietlenia
		std::cin >> n >> p;
		person* people = new person[n]; // Struktury zawieraj¹ce dane o osobach
		ushort* indexes = new ushort[n]; // Indeksy
		for (ushort i = 0; i < n; ++i) {
			std::cin >> people[i].name >> people[i].time;
			indexes[i] = i;
		}

		/* Insertion sort */

		for (ushort i = 1; i < n; ++i) {
			uint focus_point = indexes[i];
			short j = i - 1;
			while (j >= 0 && people[indexes[j]] > people[focus_point]) {
				indexes[j + 1] = indexes[j];
				--j;
			}
			indexes[j + 1] = focus_point;
		}

		/* Wyœwietlenie */
		for (ushort i = 0; i < p; ++i) {
			std::cout << people[indexes[i]].name << " ";
		}
		ullint sum = n;
		for (ushort i = 1; i < n; ++i) {
			sum += people[indexes[i]].time * i;
			sum %= 1000003;
		}
		std::cout << std::endl << sum << std::endl;
	}
	return 0;
}