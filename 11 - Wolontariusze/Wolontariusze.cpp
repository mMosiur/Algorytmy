#include <iostream>
#include <stack>
#include <vector>

typedef unsigned short ushort;

struct Edge {
	ushort station_1, station_2; // Stacja na koñcu krawêdzi
};

int main() {
	ushort t;
	std::cin >> t; // Liczba zestawów danych
	while (t-- > 0) {
		ushort n; // Liczba stacji kolejowych
		ushort m; // Liczba odcinków kolejowych bezpoœrednio ³¹cz¹cych ze sob¹ dwie stacje kolejowe
		ushort r; // Liczba wolontariuszy
		std::cin >> n >> m >> r;
		std::vector<Edge> edges;
		while (m-- > 0) {
			ushort a, b;
			std::cin >> a >> b;
			edges.push_back({ a,b });
			edges.back().station_1;
			std::vector<Edge*>* vertices = new std::vector<Edge*>[n];
			vertices[edges.back().station_1].push_back(&edges.back());
			vertices[edges.back().station_2].push_back(&edges.back());
		}
	}

	return 0;
}

/*
Mamy listê krawêdzi
Backtracking za ka¿dym razem dorzuca jeden wierzcho³ek
Za ka¿dym razem przegl¹da krawêdzie, gdzie jest 0 (s¹ nieobsadzone) i dorzucamy jeden z wierzcho³ków do listy wierzcho³ków

Pierwsza niezerowa krawêdŸ, wybieramy jeden jej wierzcho³ek i wszystkim krawêdziom z tym wierzcho³kiem zwiêkszamy licznik
Powtarzamy
Gdy braknie osób zawracamy, zdejmujemy ostatni wierzcho³ek z listy i dekrementujemy licznik wszystkim krawêdziom ze zdjêt¹ wartoœci¹
*/