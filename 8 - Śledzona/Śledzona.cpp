#include <iostream>
#include <string>
#include "test.h"

typedef unsigned int uint;

struct Position {
	uint x;
	uint y;
};

std::string test(Position& p, unsigned& id) {
	return test(p.x, p.y, id);
}

std::ostream& operator <<(std::ostream& out, const Position& p) {
	out << p.x << " " << p.y;
	return out;
}

class Robot {
	uint room_length, room_width;
	uint nof_trackers;


	Position search_for_tracker(uint& tracker_id) {
		Position pos = { room_length / 2, room_width / 2 };
		uint jump_x = pos.x / 2;
		uint jump_y = pos.y / 2;
		for (std::string direction = test(pos, tracker_id); !direction.empty(); direction = test(pos, tracker_id)) {
			if (direction.find_first_of('N') != std::string::npos) {
				pos.y += jump_y;
				jump_y /= 2;
				if (jump_y == 0) jump_y = 1;
			} else if (direction.find_first_of('S') != std::string::npos) {
				pos.y -= jump_y;
				jump_y /= 2;
				if (jump_y == 0) jump_y = 1;
			}
			if (direction.find_first_of('E') != std::string::npos) {
				pos.x += jump_x;
				jump_x /= 2;
				if (jump_x == 0) jump_x = 1;
			} else if (direction.find_first_of('W') != std::string::npos) {
				pos.x -= jump_x;
				if (jump_x == 0) jump_x = 1;
			}
		}
		return pos;
	}
public:
	Robot(uint length, uint width, uint nof_trackers) : room_length(length), room_width(width), nof_trackers(nof_trackers) {}
	void search() {
		for (uint id = 0; id < nof_trackers; id++) {
			std::cout << search_for_tracker(id) << std::endl;
		}
	}
};

int main() {
	// Magiczna linijka?
	uint x; // Szerokość mieszkania Partycji
	uint y; // Długość mieszkania Partycji
	uint t; // Ilość pluskiew w mieszkaniu Partycji
	std::cin >> x >> y >> t;

	Robot robot(x, y, t);

	robot.search();

	return 0;
}