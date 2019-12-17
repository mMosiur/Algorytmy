#include <iostream>
#include <algorithm>
#include <vector>

typedef unsigned short ushort;
typedef unsigned int uint;

// Struktura opisuj�ca pasa�era poci�gu
struct Passenger {
	uint starting_station; // Numer stacji, na kt�rej pasa�er wsiada do poci�gu
	uint destination; // Numer stacji, na kt�rej pasa�er wysiada z poci�gu

	// Konstruktor pobieraj�cy dane pasa�era z standardowego wej�cia
	Passenger() {
		std::cin >> starting_station >> destination;
	}

	// Operator por�wnuj�cy pasa�er�w, zwraca, czy pasa�er wysiada p�niej ni� podany w argumencie
	bool operator < (const Passenger& other) const {
		return destination > other.destination;
	}
};

// Klasa opisuj�ca poci�g
class Train {
	std::vector<Passenger> passengers; // Wektor wszystkich pasa�er�w w poci�gu

public:

	// Konstruktor przyjmuj�cy liczb� pasa�er�w, wczytuj�cy ich dane i sortuj�cy wzgl�dem numeru stacji wysiadania
	Train(uint nof_passengers) {
		while (nof_passengers-- > 0) {
			passengers.push_back(Passenger());
		}
		std::sort(passengers.begin(), passengers.end());
	}

	// Funkcja zwracaj�ca ilo�� minimalnej liczby spacer�w
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

	ushort t; // Liczba zestaw�w danych (1 - 2,000)
	std::cin >> t;
	while (t-- > 0) {

		uint n; // Liczba pasa�er�w poci�gu (1 - 200,000)
		std::cin >> n;

		Train train(n); // Obiekt poci�gu

		std::cout << train.nof_walks() << std::endl;

	}
	return 0;
}