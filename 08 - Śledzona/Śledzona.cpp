#include <iostream>
#include <string>
#include "test.h"

typedef unsigned int uint;

std::string test(unsigned& x, unsigned& y, unsigned& id); // Deklaracja funkcji test, której definicja zostanie dołączona do rozwiązania

// Struktura opisująca pozycję
struct Position {
	uint x; // Pozycja w poziomie
	uint y; // Pozycja w pionie

	// Operator dzielący oba koordynaty pozycji jednocześnie
	Position operator/(const uint& div) const {
		return { x / div, y / div };
	}
};

// Funkcja wywołująca funkcję test dla podanej pozycji
std::string test(Position& pos, unsigned& id) {
	return test(pos.x, pos.y, id);
}

// Operator wypiujący pozycję
std::ostream& operator <<(std::ostream& out, const Position& p) {
	out << p.x << " " << p.y;
	return out;
}

// Klasa opisująca robota wyszukującego pluskwy
class Robot {
	Position corner; // Skrajny punkt mieszkania
	Position current_position; // Pozycja robora w mieszkaniu
	Position jump_length; // Długość skoku

	// Funkcja wykonująca skos w podanym kierunku
	void jump(std::string direction) {
		if (direction.find_first_of('N') != std::string::npos) {
			current_position.y += jump_length.y;
		} else if (direction.find_first_of('S') != std::string::npos) {
			current_position.y -= jump_length.y;
		}
		if (direction.find_first_of('E') != std::string::npos) {
			current_position.x += jump_length.x;
		} else if (direction.find_first_of('W') != std::string::npos) {
			current_position.x -= jump_length.x;
		}
		jump_length = jump_length / 2;
		if (jump_length.x == 0) jump_length.x = 1;
		if (jump_length.y == 0) jump_length.y = 1;
	}

	// Funkcja wyszukująca pluskwę o podanym ID i zwracająca jej pozycję
	Position find_tracker(uint& tracker_id) {
		current_position = corner / 2;
		jump_length = current_position / 2;
		std::string direction;
		while (!(direction = test(current_position, tracker_id)).empty()) {
			jump(direction);
		}
		return current_position;
	}

public:

	// Konstruktor pobierający wymiary pokoju
	Robot(uint width, uint length) :
		corner{ width, length },
		current_position(corner / 2),
		jump_length(current_position / 2) {}

	// Funkcja wyszukująca wszystkie pluskwy i wypisująca ich pozycje
	void search(uint nof_trackers) {
		for (uint id = 0; id < nof_trackers; id++) {
			std::cout << find_tracker(id) << std::endl;
		}
	}
};

int main() {
	uint x; // Szerokość mieszkania Partycji
	uint y; // Długość mieszkania Partycji
	uint t; // Ilość pluskiew w mieszkaniu Partycji
	std::cin >> x >> y >> t;

	Robot robot(x, y); // Robot wyszukujący pluskwy

	robot.search(t); // Znalezienie i wypisanie pozycji pluskiew

	return 0;
}