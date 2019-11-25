#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

typedef unsigned short ushort;
typedef unsigned int uint;

// Vertex representing a person, contatining information about its neighbors
struct Vertex {
	uint nof_incoming_edges = 0; // The number of vertices thath should be before this one
	std::vector<Vertex*> outgoing_edges; // Vertices that should be after this one
};

// Graph representing reations between people
class Graph {
	std::map<std::string, Vertex*> vertices; // The map of vertices, where the name of a person is the key to vertex that describes it
	std::stringstream path; // The stream that contains the path from the assistant
public:

	// Constructor, loads all needed data
	Graph(uint nof_vertices, uint nof_edges) {
		// Load people into the graph
		while (nof_vertices-- > 0) {
			std::string name;
			std::cin >> name;
			vertices[name] = new Vertex;
		}
		// Load connections into the graph
		while (nof_edges-- > 0) {
			std::string from, to;
			std::cin >> from >> to;
			add_edge(vertices[from], vertices[to]);
		}
		// Load the assistant's path
		std::string path_str;
		std::cin.get(); // Get rid of the newline in the buffor
		std::getline(std::cin, path_str);
		path.str(path_str);
	}

	// Descrutor which deletes all vertices of the graph upon deletion
	~Graph() {
		for (auto& vertex : vertices) {
			delete vertex.second;
		}
	}

	// The funtion that checks and returns wether the path in this graph is correct
	bool is_path_correct() {
		while (vertices.size() > 0) {
			std::string name;
			path >> name;
			Vertex* person = vertices[name];
			if (person->nof_incoming_edges > 0) return false;
			vertices.erase(name);
			for (auto& vertex : person->outgoing_edges) {
				vertex->nof_incoming_edges--;
			}
			delete person;
		}
		return true;
	}

	// Adds an edge in the graph between two vertices
	void add_edge(Vertex* from, Vertex* to) {
		from->outgoing_edges.push_back(to);
		to->nof_incoming_edges++;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);

	ushort t; // The number of data sets
	std::cin >> t;

	while (t-- > 0) {
		uint n; // The number of people (vertices)
		uint m; // The number of pairs describing path's order (edges)
		std::cin >> n >> m;

		Graph graph(n, m); // The graph representing relations between people in this data set

		std::cout << (graph.is_path_correct() ? "TAK" : "NIE") << std::endl;
	}

	return 0;
}