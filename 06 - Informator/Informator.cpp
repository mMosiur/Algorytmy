#include <iostream>
#include <queue>

typedef unsigned short ushort;
typedef unsigned int uint;

// Structure describing a path from the starting point
struct Path {
	uint distance = 0; // The distance from the starting point
	uint monitored_sectors = 0; // Number of monitored sectors crossed
};

// Structure describing a given sector of the map
struct Sector {
	bool monitored; // Is the sector monitored

	// Pointers to he neighbors of the Sector, nullptr means no neighbor in that direction
	// [0] - up
	// [1] - right
	// [2] - down
	// [3] - left
	Sector* neighbors[4];
	Path path; // Path from the starting point

	// Constructor, sets the monitored status of the sector
	Sector(bool t_monitored = false) : monitored(t_monitored), neighbors{ nullptr,  nullptr , nullptr , nullptr }{}
};

class Map {
	Sector* start = nullptr; // A pointer to the starting point of the map
	Sector* end = nullptr; // A pointer to the finish point of the map
public:

	// A constructor, takes in a map of a given width and length and constructs a graph of the map
	Map(ushort nof_rows, ushort nof_cols) {
		Sector** map_grid = new Sector * [nof_rows * nof_cols]; // Table of pointers representing a map
		// Input data into the table and create Sectors
		for (uint i = 0; i < (uint)nof_rows * nof_cols; ++i) {
			char sector_sign;
			std::cin >> sector_sign;
			switch (sector_sign) {
			case '.':
				map_grid[i] = new Sector();
				break;
			case '#':
				map_grid[i] = nullptr;
				break;
			case 'M':
				map_grid[i] = new Sector(true);
				break;
			case 'S':
				start = map_grid[i] = new Sector();
				break;
			default: // case 'X':
				end = map_grid[i] = new Sector();
				break;
			}
		}
		// Generate a graph based on the table
		for (ushort r = 0; r < nof_rows; ++r) {
			for (ushort c = 0; c < nof_cols; ++c) {
				uint i = r * nof_cols + c;
				if (map_grid[i] == nullptr) continue;
				if (r > 0) {
					map_grid[i]->neighbors[0] = map_grid[i - nof_cols];
				}
				if (c < nof_cols - 1) {
					map_grid[i]->neighbors[1] = map_grid[i + 1];
				}
				if (r < nof_rows - 1) {
					map_grid[i]->neighbors[2] = map_grid[i + nof_cols];
				}
				if (c > 0) {
					map_grid[i]->neighbors[3] = map_grid[i - 1];
				}
			}
		}
		delete[] map_grid; // Delete the table
	}

	// Return a best Path to the finish point of the Map
	Path best_path() {
		std::queue<Sector*> queue;
		queue.push(start);
		while (!queue.empty()) {
			Sector* pos = queue.front();
			for (ushort i = 0; i < 4; i++) {
				Sector* neighbor = pos->neighbors[i];
				if (neighbor == nullptr || neighbor == start) continue;
				Path new_path = {
					pos->path.distance + 1,
					pos->path.monitored_sectors + neighbor->monitored
				};
				if (neighbor->path.distance == 0 || (neighbor->path.distance == new_path.distance && neighbor->path.monitored_sectors > new_path.monitored_sectors)) {
					neighbor->path = new_path;
					queue.push(neighbor);
				}
			}
			queue.pop();
		}
		return end->path;
	}

};

int main() {
	std::ios_base::sync_with_stdio(false);

	ushort n, m;
	std::cin >> n >> m;

	Map map(n, m);

	Path best_path = map.best_path();

	std::cout << best_path.distance << " " << best_path.monitored_sectors << std::endl;

	return 0;
}