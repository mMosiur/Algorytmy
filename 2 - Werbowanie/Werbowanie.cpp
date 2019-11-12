#include <iostream>
#include <string>

typedef unsigned short ushort;
typedef unsigned long long int ullint;

struct person {
	std::string name;
	int time;
	bool operator > (const person& other) const {
		if (this->time < other.time) return true;
		else if (this->time > other.time) return false;
		else if (this->name > other.name) return true;
		else return false;
	}
};

void insertion_sort(person* people, ushort n) {
	for (ushort i = 1; i < n; ++i) {
		person focus_point = people[i];
		int j = i - 1;
		while (j >= 0 && people[j] > focus_point) {
			people[j + 1] = people[j];
			--j;
		}
		people[j + 1] = focus_point;
	}
}

int main() {
	ushort t;
	std::cin >> t;
	while (t-- > 0) { // Przejêcie po wszystkich zestawach danych

		/* Wczytanie danych */

		ushort n; // Liczba nazwisk
		ushort p; // Liczna nazwisk do wyœwietlenia
		std::cin >> n >> p;
		person* people = new person[n]; // Struktury zawieraj¹ce dane o osobach
		for (ushort i = 0; i < n; ++i) {
			std::cin >> people[i].name >> people[i].time;
		}

		/* Insertion sort */

		insertion_sort(people, n);

		/* Wyœwietlenie */
		for (ushort i = 0; i < p; ++i) {
			std::cout << people[i].name << " ";
		}
		ullint sum = n;
		for (ushort i = 1; i < n; ++i) {
			sum += (ullint)people[i].time * i;
			sum %= 1000003;
		}
		std::cout << std::endl << sum << std::endl;

		delete[] people;
	}
	return 0;
}