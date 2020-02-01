#include <iostream>

typedef unsigned int uint;
typedef unsigned long long ulonglong;

// Funkcja zwracaj¹ca liczbê 'num' do potêgi 'pow' modulo 'mod' algorytmem wieloktronych kwadratów
uint power_modulo(uint num, uint pow, uint mod) {
	if(pow == 0) return 1;
	if(pow % 2) return ((ulonglong)num * power_modulo(num, pow - 1, mod)) % mod;
	uint result = power_modulo(num, pow / 2, mod);
	return ((ulonglong)result * result) % mod;
}

// Funkcja zwracaj¹ca odwrotnoœæ liczby 'num' modulo 'mod'
uint inverse(uint num, uint mod) {
	int t1 = 1;
	int t2 = 0;
	int t3 = 1;
	while(mod > 1) {
		uint q = mod / num;
		uint r = mod % num;
		t1 = t2;
		t2 = t3;
		t3 = t1 - q * t2;
		// Nastêpne wartoœci mod oraz num
		mod = num;
		num = r;
	}
	if(t2 < 0) t2 += t3;
	return t2;
}

// Klasa rozszyfrowuj¹ca kod
class Decryptor {
	uint private_key; // Klucz prywatny

public:
	uint n; // Liczba modulo dla dzia³añ
	uint public_key; // Klucz publiczny

	// Konstruktor przyjmuj¹cy liczby pierwsze p i q oraz klucz publiczny, licz¹cy dla nich klucz prywatny
	Decryptor(uint p, uint q, uint public_key) : n(p * q), public_key(public_key) {
		uint phi = (p - 1) * (q - 1);
		private_key = inverse(public_key, phi);
	}

	// Funkcja przyjmuj¹ca zaszyfrowan¹ wartoœæ, rozszyfrowuj¹ca j¹ i zwracaj¹ca wynik
	uint decrypt(uint encrypted_value) {
		return power_modulo(encrypted_value, private_key, n);
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);

	uint t; // Liczba zestawów danych
	std::cin >> t;
	for(uint i = 0; i < t; i++) {

		uint p; // Liczba pierwsza p
		uint q; // Liczba pierwsza q
		uint e; // Klucz publiczny
		uint c; // Zaszyfrowana wiadomoœæ
		std::cin >> p >> q >> e >> c;

		Decryptor decryptor(p, q, e);

		std::cout << decryptor.decrypt(c) << std::endl;

	}

	return 0;
}