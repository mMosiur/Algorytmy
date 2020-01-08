#include <iostream>
#include <vector>

typedef unsigned short ushort;

struct Connection;

// Strkutura reprezentuj�ca stacj�
struct Station {
	ushort number; // Numer stacji
	bool is_watched; // Czy stacja jest obsadzona
	std::vector<Connection*> connections_to; // Wektor wska�nik�w na po��czenia z ko�cem w tej stacji

	// Konstruktor inicjalizuj�cy zmienne
	Station(ushort s) : number(s), is_watched(false) {}
};

// Struktura reprezentuj�ca po��czenie mi�dzy stacjami
struct Connection {
	Station* station_a; // Wska�nik na stacj� ko�cow� tego po��czenia
	Station* station_b; // Wska�nik na stacj� ko�cow� tego po��czenia

	// Funkcja zwracaj�ca, czy dane po��czenie jest obserwowane
	bool is_watched() {
		return station_a->is_watched || station_b->is_watched;
	}

	// Konstruktor inicjalizuj�cy zmienne
	Connection(Station* a, Station* b) : station_a(a), station_b(b) {}
};

// Klasa reprezentuj�ca system obserwowania stacji i po��cze� mi�dzy nimi
class WatchSystem {
	std::vector<Station*> stations; // Wektor wszystkich stacji
	std::vector<Connection*> connections; // Wektor wszystkich po��cze� mi�dzy stacjami
	ushort nof_volunteers_available;
public:

	// Konstruktor inicjalizuj�cy zmienne i przyjmuj�cy odpowiednie dane
	WatchSystem(ushort nof_stations, ushort nof_connections, ushort nof_volunteers) : nof_volunteers_available(nof_volunteers) {
		for(ushort i = 0; i < nof_stations; i++) {
			stations.push_back(new Station(i + 1));
		}
		for(ushort i = 0; i < nof_connections; i++) {
			ushort a, b; // numery stacji kolejowych po��czonych bezpo�rednim odcinkiem tor�w
			std::cin >> a >> b;
			connections.push_back(new Connection(get_station(a), get_station(b)));
		}
	}

	// Funkcja zwracaj�ca stacj� o podanym numerze
	Station* get_station(ushort number) {
		return stations[number - 1];
	}

	// Funkcja dodaj�ca stacj� do obserwowanych
	void add_to_watch(Station* station) {
		if(nof_volunteers_available == 0) return;
		station->is_watched = true;
		nof_volunteers_available--;
	}

	// Funkcja usuwaj�ca stacj� z obserwowanych
	void remove_from_watch(Station* station) {
		if(!station->is_watched) return;
		station->is_watched = false;
		nof_volunteers_available++;
	}

	// Funkcja zwracaj�ca, czy wszystkie po��czenia s� obserwowane
	bool everything_watched() {
		for(auto& connection : connections) {
			if(!connection->is_watched()) return false;
		}
		return true;
	}

	// Funkcja zwracaj�ca, czy wolontariuszy wystarczy do obsadzenia systemu kolejowego
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
	ushort t; // Liczba zestaw�w danych
	std::cin >> t;
	for(ushort i = 0; i < t; i++) {
		ushort n; // Liczba stacji kolejowych
		ushort m; // Liczba odcink�w kolejowych bezpo�rednio ��cz�cych ze sob� dwie stacje kolejowe
		ushort r; // Liczba wolontariuszy
		std::cin >> n >> m >> r;

		WatchSystem system_obserwowania(n, m, r);

		std::cout << (system_obserwowania.enough_volunteers() ? "TAK" : "NIE") << std::endl;

	}
	return 0;
}