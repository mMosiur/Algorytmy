#include <iostream>
#include <stack>
#include <vector>

typedef unsigned short ushort;

struct Edge {
	ushort station_1, station_2; // Stacja na ko�cu kraw�dzi
};

int main() {
	ushort t;
	std::cin >> t; // Liczba zestaw�w danych
	while (t-- > 0) {
		ushort n; // Liczba stacji kolejowych
		ushort m; // Liczba odcink�w kolejowych bezpo�rednio ��cz�cych ze sob� dwie stacje kolejowe
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
Mamy list� kraw�dzi
Backtracking za ka�dym razem dorzuca jeden wierzcho�ek
Za ka�dym razem przegl�da kraw�dzie, gdzie jest 0 (s� nieobsadzone) i dorzucamy jeden z wierzcho�k�w do listy wierzcho�k�w

Pierwsza niezerowa kraw�d�, wybieramy jeden jej wierzcho�ek i wszystkim kraw�dziom z tym wierzcho�kiem zwi�kszamy licznik
Powtarzamy
Gdy braknie os�b zawracamy, zdejmujemy ostatni wierzcho�ek z listy i dekrementujemy licznik wszystkim kraw�dziom ze zdj�t� warto�ci�
*/