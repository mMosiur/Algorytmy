#include <iostream>
#include <string>
#include <map>
#include <vector>

typedef unsigned short ushort;
typedef unsigned int uint;

struct Vertex {
	std::string name;
	uint nof_incoming_edges = 0;
	std::vector<Vertex*> outgoing_edges;

	Vertex(std::string name) : name(name) {}

	void add_edge(Vertex* to) {
		outgoing_edges.push_back(to);
		to->nof_incoming_edges++;
	}
};

class Graph {
	std::map<std::string, Vertex*> vertices;

public:
	Graph(uint nof_vertices, uint nof_edges) {
		// Load people into the graph
		while (nof_vertices-- > 0) {
			std::string name;
			std::cin >> name;
			vertices[name] = new Vertex(name);
		}
		// Load connections into the graph
		while (nof_edges-- > 0) {
			std::string from, to;
			std::cin >> from >> to;
			Vertex* first = vertices[from];
			Vertex* second = vertices[to];
			first->add_edge(second);
		}
	}

	bool is_path_correct() {
		uint nof_vertices = vertices.size();
		while (nof_vertices-- > 0) {
			std::string name;
			std::cin >> name;
			Vertex* person = vertices[name];
			vertices.erase(name);
			if (person->nof_incoming_edges != 0) return false;
			for (auto& v : person->outgoing_edges) v->nof_incoming_edges--;
			delete person;
		}
		return true;
	}

	~Graph() {
		for (auto& vertex : vertices) {
			delete vertex.second;
		}
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);

	ushort t; // The number of data sets
	std::cin >> t;

	while (t-- > 0) {
		uint n, m;
		std::cin >> n >> m;

		Graph graph(n, m);

		std::cout << (graph.is_path_correct() ? "TAK" : "NIE") << std::endl;

	}

	return 0;
}