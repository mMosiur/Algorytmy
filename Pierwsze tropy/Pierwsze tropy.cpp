#include <iostream>

unsigned int check_set() {
	int n; // Liczba trop�w (1-1000000)
	int m; // Liczba metod (1-1000000)
	int x; // Liczba analizowanych trop�w w metodzie
	int y; // Liczba powstaj�cych trop�w w metodzie
	int max_x = 0; // Najwi�ksza liczba trop�w analizowanych w metodzie
	int max_diff = 0; // Najwi�ksza r�nica mi�dzy liczb� analizowanych trop�w a powsta�ych trop�w
	
	std::cin >> n >> m;

	for (short j = 0; j < m; ++j) {
		std::cin >> x >> y;
		if (max_x < x) {
			if (x >= n) return 1;
			max_x = x;
		}
		if (max_diff < (x - y)) {
			max_diff = x - y;
		}
	}

	if (max_diff > 0) {
		return (n - max_x) / max_diff + ((n - max_x) % max_diff > 0) + 1;
	}
	else {
		return 0;
	}

}

int main() {
	std::ios_base::sync_with_stdio(false);

	short t; // Liczba zestaw�w danych (1-10)

	std::cin >> t;

	for (short i = 0; i < t; ++i) {
		int result = check_set();
		std::cout << result ? result : "BRAK METOD";
	}

	return 0;
}