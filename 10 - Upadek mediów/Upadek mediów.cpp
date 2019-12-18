#include <iostream>
#include <vector>

typedef unsigned short ushort;
typedef unsigned int uint;

// Struktura opisuj¹ca cytowanie jednej gazety w drugiej
struct Citation {
	ushort newspaper; // Numer medium cytuj¹cego
	ushort day; // Dzieñ cytowania
	ushort cited_newspaper; // Numer medium cytowanego
	ushort cited_day; // Dzieñ, z którego pochodzi cytowanie
};

// Klasa opisuj¹ca relacjê analizowanych mediów
class Medias {
	std::vector<Citation> citations[7]; // Tablica wektorów cytowañ, ka¿dy wektor przechowuje cytowania z danego dnia
	ushort nof_medias; // Liczba mediów do przeanalizowania
	ushort day; // Aktualny dzieñ tygodnia
	uint nof_days_left; // Pozosta³a liczba dni do analizy
	uint* week[7]; // Tabela pomocnicza tygodnia, PROGRAMOWANIE DYNAMICZNE

public:

	// Konstruktor, przyjmuje wymagane dane, wczytuje je do obiektu, inicjalizuje tabelê pomocnicz¹ tygodnia oraz wczytuje cytowañ
	Medias(ushort n, ushort s, ushort d, uint l, ushort m) : nof_medias(n), day(d), nof_days_left(l) {
		// Inicjalizacja tabeli pomocniczej tygodnia
		for (ushort i = 0; i < 7; i++) {
			week[i] = new uint[n];
			for (ushort j = 0; j < n; j++) week[i][j] = 0;
		}
		week[d][s] = 1;
		// Wczytanie cytowañ
		for (ushort i = 0; i < m; i++) {
			ushort a, b, c, d;
			std::cin >> a >> b >> c >> d;
			citations[b].push_back({ a,b,c,d });
		}
	}

	// Funkcja zwracaj¹ca podsumowanie dnia
	uint day_summary() {
		uint day_summary = 0;
		for (ushort media = 0; media < nof_medias; media++) {
			day_summary += week[day][media];
			day_summary %= 100000007;
		}
		return day_summary;
	}

	// Przechodz¹ca w nastêpny dzieñ, zwraca false gdy skoñczy³y siê dni do analizowania
	bool next_day() {
		if (--nof_days_left == 0) return false;
		day = (day + 1) % 7;
		for (ushort media = 0; media < nof_medias; media++) week[day][media] = 0; // Wyzeruj nowy dzieñ
		return true;
	}

	// Funkcja zwracaj¹ca szukan¹ liczbê krawêdzi grafu cytowañ
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
	ushort n; // Liczba analizowanych mediów (1-300)
	ushort s; // Medium, które jako pierwsze otrzyma³o informacjê (0-299)
	ushort d; // Dzieñ tygodnia publikacji informacji (0-6)
	uint l;   // Liczba dni, kiedy informacja rozprzestrzenia³a siê (1-100000)
	ushort m; // Liczba krawêdzi w "grafie cytowañ" (1-2000)
	std::cin >> n >> s >> d >> l >> m;

	Medias medias(n, s, d, l, m);

	std::cout << medias.nof_citations_paths() << std::endl;

	return 0;
}