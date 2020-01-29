#include <iostream>

typedef unsigned int uint;
typedef unsigned long long ulonglong;

// Funkcja zwracaj�ca liczb� 'num' do pot�gi 'pow' modulo 'mod' algorytmem wieloktronych kwadrat�w
uint power_modulo(uint num, uint pow, uint mod) {
	if(pow == 0) return 1;
	if(pow % 2) return ((ulonglong)num * power_modulo(num, pow - 1, mod)) % mod;
	uint result = power_modulo(num, pow / 2, mod);
	return ((ulonglong)result * result) % mod;
}

// Funkcja zwracaj�ca odwrotno�� liczby 'num' modulo 'mod'
uint inverse(uint num, uint mod) {
	uint m0 = mod;
	int y = 0, x = 1;
	while(num > 1) {
		uint q = num / m0;
		long temp = m0;
		m0 = num % m0;
		num = temp;
		temp = y;
		y = x - q * y;
		x = temp;
	}
	if(x < 0) x += mod;
	return x;
}

// Klasa rozszyfrowuj�ca kod
class Decryptor {
	uint private_key; // Klucz prywatny

public:
	uint n; // Liczba modulo dla dzia�a�
	uint public_key; // Klucz publiczny

	// Konstruktor przyjmuj�cy liczby pierwsze p i q oraz klucz publiczny, licz�cy dla nich klucz prywatny
	Decryptor(uint p, uint q, uint public_key) : n(p * q), public_key(public_key) {
		uint phi = (p - 1) * (q - 1);
		private_key = inverse(public_key, phi);
	}

	// Funkcja przyjmuj�ca zaszyfrowan� warto��, rozszyfrowuj�ca j� i zwracaj�ca wynik
	uint decrypt(uint encrypted_value) {
		return power_modulo(encrypted_value, private_key, n);
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);

	uint t; // Liczba zestaw�w danych
	std::cin >> t;
	for(uint i = 0; i < t; i++) {

		uint p; // Liczba pierwsza p
		uint q; // Liczba pierwsza q
		uint e; // Klucz publiczny
		uint c; // Zaszyfrowana wiadomo��
		std::cin >> p >> q >> e >> c;

		Decryptor decryptor(p, q, e);

		std::cout << decryptor.decrypt(c) << std::endl;

	}

	return 0;
}