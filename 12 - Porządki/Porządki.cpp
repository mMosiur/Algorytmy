#include <iostream>
#include <list>

typedef unsigned short ushort;
typedef unsigned int uint;

// Struktura opisuj¹ca pojedynczy dokument
struct Document {
	uint unique_number; // Unikalny numer dokumentu (0 - n)
	ushort priority; // Priorytet (0 - 10)
	uint random_code; // Losowy kod (0 - 10000000)
	short subject_symbols[4]; // Tablica zawieraj¹ca symbole tematyki dokumentu, nieistniej¹cy symbol oznaczany jest przez -1 (0-255)

	// Konstruktor inicjalizuj¹cy i przyjmuj¹cy zmienne
	Document() : subject_symbols{ -1,-1,-1,-1 } {
		std::cin >> unique_number >> priority >> random_code;
		ushort nof_subject_symbols;
		std::cin >> nof_subject_symbols;
		for(ushort i = 0; i < nof_subject_symbols; i++) {
			std::cin >> subject_symbols[i];
		}
	}
};

// Klasa sortuj¹ca dokumenty
class DocumentSorter {
	std::list<Document> documents; // Lista wszystkich dokumentów
	std::list<ushort> sorting_order; // Kolejnoœæ parametrów sortowania
	
	// Funkcja wykonuj¹ca sortowanie kube³kowe na podanym parametrze
	void bucket_sort(ushort sorting_parameter) {
		std::list<Document>* buckets;

		if(sorting_parameter == 1) { // Sortowanie na unikalnych numerach dokumentów
			ushort nof_buckets = (documents.size() - 1) / 1000 + 1;
			std::list<Document>* buckets = new std::list<Document>[nof_buckets];
			auto documents_iterator = documents.begin();
			while(documents_iterator != documents.end()) {
				ushort unique_number = documents_iterator->unique_number;
				buckets[unique_number / 1000].splice(buckets[unique_number / 1000].end(), documents, documents_iterator++);
			}
			for(ushort i = 0; i < nof_buckets; i++) {
				buckets[i].sort(
					[](const Document& doc1, const Document& doc2) {
					return doc1.unique_number < doc2.unique_number;
					}
				);
				documents.splice(documents.end(), buckets[i]);
			}
			delete[] buckets;
		} else if(sorting_parameter == 2) { // Sortowanie na priorytetach dokumentów
			buckets = new std::list<Document>[11];
			auto documents_iterator = documents.begin();
			while(documents_iterator != documents.end()) {
				ushort priority = documents_iterator->priority;
				buckets[priority].splice(buckets[priority].end(), documents, documents_iterator++);
			}
			for(ushort i = 0; i < 11; i++) {
				if(buckets[i].empty()) continue;
				documents.splice(documents.end(), buckets[i]);
			}
			delete[] buckets;
		} else if(sorting_parameter == 3) { // Sortowanie na losowych kodach dokumentów
			buckets = new std::list<Document>[10000];
			auto documents_iterator = documents.begin();
			while(documents_iterator != documents.end()) {
				uint random_code = documents_iterator->random_code;
				if(random_code == 10000000) random_code = 9999999;
				buckets[random_code / 1000].splice(buckets[random_code / 1000].end(), documents, documents_iterator++);
			}
			for(ushort i = 0; i < 10000; i++) {
				if(buckets[i].empty()) continue;
				buckets[i].sort(
					[](const Document& doc1, const Document& doc2) {
						return doc1.random_code < doc2.random_code;
					}
				);
				documents.splice(documents.end(), buckets[i]);
			}
			delete[] buckets;
		} else if(sorting_parameter == 4) { // Sortowanie na symbolach tematyki dokumentów
			for(short i = 3; i >= 0; i--) { // Sortowanie na ka¿dym symbolu od ty³u
				buckets = new std::list<Document>[257];
				auto documents_iterator = documents.begin();
				while(documents_iterator != documents.end()) {
					short subject_symbol = documents_iterator->subject_symbols[i] + 1;
					buckets[subject_symbol].splice(buckets[subject_symbol].end(), documents, documents_iterator++);
				}
				for(ushort i = 0; i < 257; i++) {
					if(buckets[i].empty()) continue;
					documents.splice(documents.end(), buckets[i]);
				}
				delete[] buckets;
			}
		}
		return;
	}

public:

	// Konstruktowa przyjmuj¹cy iloœæ dokumentów i wczytuj¹cy je oraz kolejnoœæ sortowania
	DocumentSorter(uint nof_documents) {
		for(uint i = 0; i < nof_documents; i++) {
			documents.emplace_back();
		}
		for(ushort i = 0; i < 4; i++) {
			ushort sorting_parameter;
			std::cin >> sorting_parameter;
			sorting_order.push_front(sorting_parameter);
			if(sorting_parameter == 1) break;
		}
	}

	// Funkcja sortuj¹ca dokumenty wielokrotnie zgodnie z zadan¹ kolejnoœci¹ sortowania
	void sort() {
		for(ushort& sorting_parameter : sorting_order) {
			bucket_sort(sorting_parameter);
		}
	}

	// Funkcja zwracaj¹ca sumê losowych kodów poszczególnych dokumentow pomno¿onych przez ich indeks modulo 100000007
	uint result() {
		uint result = 0;
		uint index = 0;
		for(Document& document : documents) {
			result += (document.random_code * index++);
			result %= 100000007;
		}
		return result;
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