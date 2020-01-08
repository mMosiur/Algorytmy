#include <iostream>
#include <vector>

typedef unsigned short ushort;

struct Connection;

// Strkutura reprezentuj¹ca stacjê
struct Station {
	ushort number; // Numer stacji
	bool is_watched; // Czy stacja jest obsadzona
	std::vector<Connection*> connections_to; // Wektor wskaŸników na po³¹czenia z koñcem w tej stacji

	// Konstruktor inicjalizuj¹cy zmienne
	Station(ushort s) : number(s), is_watched(false) {}
};

// Struktura reprezentuj¹ca po³¹czenie miêdzy stacjami
struct Connection {
	Station* station_a; // WskaŸnik na stacjê koñcow¹ tego po³¹czenia
	Station* station_b; // WskaŸnik na stacjê koñcow¹ tego po³¹czenia

	// Funkcja zwracaj¹ca, czy dane po³¹czenie jest obserwowane
	bool is_watched() {
		return station_a->is_watched || station_b->is_watched;
	}

	// Konstruktor inicjalizuj¹cy zmienne
	Connection(Station* a, Station* b) : station_a(a), station_b(b) {}
};

// Klasa reprezentuj¹ca system obserwowania stacji i po³¹czeñ miêdzy nimi
class WatchSystem {
	std::vector<Station*> stations; // Wektor wszystkich stacji
	std::vector<Connection*> connections; // Wektor wszystkich po³¹czeñ miêdzy stacjami
	ushort nof_volunteers_available;
public:

	// Konstruktor inicjalizuj¹cy zmienne i przyjmuj¹cy odpowiednie dane
	WatchSystem(ushort nof_stations, ushort nof_connections, ushort nof_volunteers) : nof_volunteers_available(nof_volunteers) {
		for(ushort i = 0; i < nof_stations; i++) {
			stations.push_back(new Station(i + 1));
		}
		for(ushort i = 0; i < nof_connections; i++) {
			ushort a, b; // numery stacji kolejowych po³¹czonych bezpoœrednim odcinkiem torów
			std::cin >> a >> b;
			connections.push_back(new Connection(get_station(a), get_station(b)));
		}
	}

	// Funkcja zwracaj¹ca stacjê o podanym numerze
	Station* get_station(ushort number) {
		return stations[number - 1];
	}

	// Funkcja dodaj¹ca stacjê do obserwowanych
	void add_to_watch(Station* station) {
		if(nof_volunteers_available == 0) return;
		station->is_watched = true;
		nof_volunteers_available--;
	}

	// Funkcja usuwaj¹ca stacjê z obserwowanych
	void remove_from_watch(Station* station) {
		if(!station->is_watched) return;
		station->is_watched = false;
		nof_volunteers_available++;
	}

	// Funkcja zwracaj¹ca, czy wszystkie po³¹czenia s¹ obserwowane
	bool everything_watched() {
		for(auto& connection : connections) {
			if(!connection->is_watched()) return false;
		}
		return true;
	}

	// Funkcja zwracaj¹ca, czy wolontariuszy wystarczy do obsadzenia systemu kolejowego
	bool enough_volunteers() {
		if(everything_watched()) return true;
		if(nof_volunteers_available == 0) return false;
		for(auto& connection : connections) {
			if(connection->is_watched()) continue;
			add_to_watch(connection->station_a);
			if(enough_volunteers()) return true;
			remove_from_watch(connection->station_a);
			add_to_watch(connection->station_b);
			if(enough_volunteers()) return true;
			remove_from_watch(connection->station_b);
		}
		return false;
	}

	// Destruktor
	~WatchSystem() {
		for(auto& station : stations) {
			delete station;
		}
		for(auto& connection : connections) {
			delete connection;
		}
	}
};

int main() {
	ushort t; // Liczba zestawów danych
	std::cin >> t;
	for(ushort i = 0; i < t; i++) {
		ushort n; // Liczba stacji kolejowych
		ushort m; // Liczba odcinków kolejowych bezpoœrednio ³¹cz¹cych ze sob¹ dwie stacje kolejowe
		ushort r; // Liczba wolontariuszy
		std::cin >> n >> m >> r;

		WatchSystem system_obserwowania(n, m, r);

		std::cout << (system_obserwowania.enough_volunteers() ? "TAK" : "NIE") << std::endl;

	}
	return 0;
}