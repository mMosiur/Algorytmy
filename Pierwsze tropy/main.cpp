#include <iostream>
#include <cmath>

int main() {
	std::ios_base::sync_with_stdio(false);

	short t; // Liczba zestawów danych (1-10)
	int n; // Liczba tropów (1-1000000)
	int m; // Liczba metod (1-1000000)

	std::cin >> t;

	int x; // Liczba analizowanych tropów w metodzie
	int y; // Liczba powstaj¹cych tropów w metodzie
	int max_x; // Najwiêksza liczba tropów analizowanych w metodzie
	int max_diff; // Najwiêksza ró¿nica miêdzy liczb¹ analizowanych tropów a powsta³ych tropów

	for (short i = 0; i < t; ++i) {
		max_x = 0;
		max_diff = 0;
		std::cin >> n >> m;
		for (short j = 0; j < m; ++j) {
			std::cin >> x >> y;
			if (max_x < x) {
				max_x = x;
			}
			if (max_diff < (x - y)) {
				max_diff = x - y;
			}
		}


		if (max_diff <= 0) {
			std::cout << "BRAK METOD" << std::endl;
		}
		else {
			std::cout << (n - max_x) / max_diff + ((n - max_x) % max_diff > 0) + 1 << std::endl;
		}

	}

	return 0;
}