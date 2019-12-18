#include <iostream>
#include <vector>

typedef unsigned short ushort;
typedef unsigned int uint;

// Struktura opisuj�ca cytowanie jednej gazety w drugiej
struct Citation {
	ushort newspaper; // Numer medium cytuj�cego
	ushort day; // Dzie� cytowania
	ushort cited_newspaper; // Numer medium cytowanego
	ushort cited_day; // Dzie�, z kt�rego pochodzi cytowanie
};

// Klasa opisuj�ca relacj� analizowanych medi�w
class Medias {
	std::vector<Citation> citations[7]; // Tablica wektor�w cytowa�, ka�dy wektor przechowuje cytowania z danego dnia
	ushort nof_medias; // Liczba medi�w do przeanalizowania
	ushort day; // Aktualny dzie� tygodnia
	uint nof_days_left; // Pozosta�a liczba dni do analizy
	uint* week[7]; // Tabela pomocnicza tygodnia, PROGRAMOWANIE DYNAMICZNE

public:

	// Konstruktor, przyjmuje wymagane dane, wczytuje je do obiektu, inicjalizuje tabel� pomocnicz� tygodnia oraz wczytuje cytowa�
	Medias(ushort n, ushort s, ushort d, uint l, ushort m) : nof_medias(n), day(d), nof_days_left(l) {
		// Inicjalizacja tabeli pomocniczej tygodnia
		for (ushort i = 0; i < 7; i++) {
			week[i] = new uint[n];
			for (ushort j = 0; j < n; j++) week[i][j] = 0;
		}
		week[d][s] = 1;
		// Wczytanie cytowa�
		for (ushort i = 0; i < m; i++) {
			ushort a, b, c, d;
			std::cin >> a >> b >> c >> d;
			citations[b].push_back({ a,b,c,d });
		}
	}

	// Funkcja zwracaj�ca podsumowanie dnia
	uint day_summary() {
		uint day_summary = 0;
		for (ushort media = 0; media < nof_medias; media++) {
			day_summary += week[day][media];
			day_summary %= 100000007;
		}
		return day_summary;
	}

	// Przechodz�ca w nast�pny dzie�, zwraca false gdy sko�czy�y si� dni do analizowania
	bool next_day() {
		if (--nof_days_left == 0) return false;
		day = (day + 1) % 7;
		for (ushort media = 0; media < nof_medias; media++) week[day][media] = 0; // Wyzeruj nowy dzie�
		return true;
	}

	// Funkcja zwracaj�ca szukan� liczb� kraw�dzi grafu cytowa�
	uint nof_citations_paths() {
		uint result = 0;
		do {
			for (Citation& citation : citations[day])
			{
				week[day][citation.newspaper] += week[citation.cited_day][citation.cited_newspaper];
				week[day][citation.newspaper] %= 100000007;
			}
			result += day_summary();
			result %= 100000007;
		} while (next_day());
		return result;
	}
};

int main() {
	ushort n; // Liczba analizowanych medi�w (1-300)
	ushort s; // Medium, kt�re jako pierwsze otrzyma�o informacj� (0-299)
	ushort d; // Dzie� tygodnia publikacji informacji (0-6)
	uint l;   // Liczba dni, kiedy informacja rozprzestrzenia�a si� (1-100000)
	ushort m; // Liczba kraw�dzi w "grafie cytowa�" (1-2000)
	std::cin >> n >> s >> d >> l >> m;

	Medias medias(n, s, d, l, m);

	std::cout << medias.nof_citations_paths() << std::endl;

	return 0;
}