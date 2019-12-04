#include <iostream>
#include <algorithm>
#include <vector>

typedef unsigned short ushort;
typedef unsigned int uint;

// Struktura opisuj¹ca pasa¿era poci¹gu
struct Passenger {
	uint starting_station; // Numer stacji, na której pasa¿er wsiada do poci¹gu
	uint destination; // Numer stacji, na której pasa¿er wysiada z poci¹gu

	// Konstruktor pobieraj¹cy dane pasa¿era z standardowego wejœcia
	Passenger() {
		std::cin >> starting_station >> destination;
	}

	// Operator porównuj¹cy pasa¿erów, zwraca, czy pasa¿er wysiada póŸniej ni¿ podany w argumencie
	bool operator < (const Passenger& other) const {
		return destination > other.destination;
	}
};

// Klasa opisuj¹ca poci¹g
class Train {
	std::vector<Passenger> passengers; // Wektor wszystkich pasa¿erów w poci¹gu

public:

	// Konstruktor przyjmuj¹cy liczbê pasa¿erów, wczytuj¹cy ich dane i sortuj¹cy wzglêdem numeru stacji wysiadania
	Train(uint nof_passengers) {
		while (nof_passengers-- > 0) {
			passengers.push_back(Passenger());
		}
		std::sort(passengers.begin(), passengers.end());
	}

	// Funkcja zwracaj¹ca iloœæ minimalnej liczby spacerów
	uint nof_walks() {
		uint nof_walks = 0;
		uint last_walk = 0;
		while (!passengers.empty()) {
			if(passengers.back().starting_station >= last_walk){
				last_walk = passengers.back().destination;
				nof_walks++;
			}
			passengers.pop_back();
		}
		return nof_walks;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);

	ushort t; // Liczba zestawów danych (1 - 2,000)
	std::cin >> t;
	while (t-- > 0) {

		uint n; // Liczba pasa¿erów poci¹gu (1 - 200,000)
		std::cin >> n;

		Train train(n); // Obiekt poci¹gu

		std::cout << train.nof_walks() << std::endl;

	}
	return 0;
}