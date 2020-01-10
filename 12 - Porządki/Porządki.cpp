#include <iostream>
#include <list>
#include <vector>

typedef unsigned short ushort;
typedef unsigned int uint;

// Struktura opisuj�ca pojedynczy dokument
struct Document {
	uint unique_number; // Unikalny numer dokumentu (0 - n)
	ushort priority; // Priorytet (0 - 10)
	uint random_code; // Losowy kod (0 - 10000000)
	short subject_symbols[4]; // Tablica zawieraj�ca symbole tematyki dokumentu, nieistniej�cy symbol oznaczany jest przez -1 (0-255)

	// Konstruktor inicjalizuj�cy i przyjmuj�cy zmienne
	Document(uint unique_number, ushort priority, uint random_code, ushort nof_subject_symbols) :
		unique_number(unique_number),
		priority(priority),
		random_code(random_code),
		subject_symbols{ -1,-1,-1,-1 } {
		for(ushort i = 0; i < nof_subject_symbols; i++) {
			std::cin >> subject_symbols[i];
		}
	}
};

// Klasa sortuj�ca dokumenty
class DocumentSorter {
	std::vector<Document*> documents; // Lista wszystkich dokument�w
	std::list<ushort> sorting_order; // Kolejno�� parametr�w sortowania

	// Funkcja wykonuj�ca sortowanie kube�kowe na podanym parametrze
	void bucket_sort(ushort sorting_parameter) {
		std::list<Document*>* buckets = nullptr;

		if(sorting_parameter == 1) { // Sortowanie na unikalnych numerach dokument�w
			std::vector<Document*> documents_copy(documents);
			for(auto& document : documents_copy) {
				documents[document->unique_number - 1] = document;
			}
		} else if(sorting_parameter == 2) { // Sortowanie na priorytetach dokument�w
			buckets = new std::list<Document*>[11];
			for(auto& document : documents) {
				buckets[document->priority].push_back(document);
			}
			uint pos = 0;
			for(ushort i = 0; i < 11; i++) {
				for(auto& document : buckets[i]) {
					documents[pos++] = document;
				}
			}
		} else if(sorting_parameter == 3) { // Sortowanie na losowych kodach dokument�w
			buckets = new std::list<Document*>[1000];
			for(auto& document : documents) {
				uint random_code = document->random_code;
				if(random_code == 10000000) random_code = 9999999;
				buckets[random_code / 10000].push_back(document);
			}
			uint pos = 0;
			for(ushort i = 0; i < 1000; i++) {
				buckets[i].sort(
					[](const auto& doc1, const auto& doc2) {
						return doc1->random_code < doc2->random_code;
					}
				);
				for(auto& document : buckets[i]) {
					documents[pos++] = document;
				}
			}
		} else if(sorting_parameter == 4) { // Sortowanie na symbolach tematyki dokument�w
			for(short i = 3; i >= 0; i--) { // Sortowanie na ka�dym symbolu od ty�u
				buckets = new std::list<Document*>[257];
				for(auto& document : documents) {
					buckets[document->subject_symbols[i] + 1].push_back(document);
				}
				uint pos = 0;
				for(ushort i = 0; i < 257; i++) {
					for(auto& document : buckets[i]) {
						documents[pos++] = document;
					}
				}
				delete[] buckets;
			}
			buckets = nullptr;
		}
		if(buckets) delete[] buckets;
	}

public:

	// Konstruktowa przyjmuj�cy ilo�� dokument�w i wczytuj�cy je oraz kolejno�� sortowania
	DocumentSorter(uint nof_documents) {
		for(uint i = 0; i < nof_documents; i++) {
			uint unique_number;
			ushort priority;
			uint random_code;
			ushort nof_subject_symbols;
			std::cin >> unique_number >> priority >> random_code >> nof_subject_symbols;
			documents.push_back(new Document(unique_number, priority, random_code, nof_subject_symbols));
		}
		for(ushort i = 0; i < 4; i++) {
			ushort sorting_parameter;
			std::cin >> sorting_parameter;
			sorting_order.push_front(sorting_parameter);
			if(sorting_parameter == 1) break;
		}
	}

	// Funkcja sortuj�ca dokumenty wielokrotnie zgodnie z zadan� kolejno�ci� sortowania
	void sort() {
		for(ushort& sorting_parameter : sorting_order) {
			bucket_sort(sorting_parameter);
		}
	}

	// Funkcja zwracaj�ca sum� losowych kod�w poszczeg�lnych dokumentow pomno�onych przez ich indeks modulo 100000007
	uint result() {
		uint result = 0;
		uint index = 0;
		for(Document*& document : documents) {
			result += (document->random_code * index++);
			result %= 100000007;
		}
		return result;
	}

	// Destruktor
	~DocumentSorter() {
		for(auto& document : documents) {
			delete document;
		}
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);

	uint n;
	std::cin >> n;

	DocumentSorter sorter(n);

	sorter.sort();

	std::cout << sorter.result() << std::endl;

	return 0;
}