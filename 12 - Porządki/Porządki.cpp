#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;

// Struktura dokumentu
struct Document {
	uint unique_number; // Unikalny numer (1 - n)
	ushort priority; // Priorytet (0 - 10)
	uint random_code; // Losowy kod (0 - 10,000,000)
	short subject_symbols[4]; // Symbole tematyki (0 - 255 oraz, -1 dla braku wartoœci)

	// Konstruktor przyjmuj¹cy oraz wczytuj¹cy dane
	Document(uint unique_number, ushort priority, uint random_code, ushort nof_subject_symbols) :
		unique_number(unique_number), priority(priority), random_code(random_code), subject_symbols{ -1,-1,-1,-1 } {
		for(ushort i = 0; i < nof_subject_symbols; i++) {
			std::cin >> subject_symbols[i];
		}
	}
};

// Klasa sortuj¹ca dokumenty
class DocumentSorter {
	std::vector<Document*> documents; // Wektor wskaŸników na dokumenty
	std::list<ushort> sorting_order; // Lista kolejnoœci sortowania

	// Funkcja sortuj¹ca dokumenty po unikalnym numerze nie jest potrzebna, poniewa¿
	// dokumenty bêd¹ sortowane bo unikalnym numerze przy wczytywaniu danych w konstruktorze.

	// Funkcja sortuj¹ca dokumenty po priorytecie
	void sort_by_priority() {
		std::vector<Document*> buckets[11];
		for(auto& doc : documents) {
			buckets[doc->priority].push_back(doc);
		}
		uint pos = 0;
		for(ushort i = 0; i < 11; i++) {
			for(auto& doc : buckets[i]) {
				documents[pos++] = doc;
			}
		}
	}

	// Funkcja sortuj¹ca dokumenty po losowym kodzie
	void sort_by_random_code() {
		std::vector<Document*>* buckets = new std::vector<Document*>[10000];
		for(auto& doc : documents) {
			ushort bucket_number = ((int)doc->random_code - 1) / 1000;
			buckets[bucket_number].push_back(doc);
		}
		uint pos = 0;
		for(ushort i = 0; i < 10000; i++) {
			if(buckets[i].empty()) continue;
			std::stable_sort(buckets[i].begin(), buckets[i].end(),
							 [](const auto& doc1, const auto& doc2) {
								 return doc1->random_code < doc2->random_code;
							 }
			);
			for(auto& doc : buckets[i]) {
				documents[pos++] = doc;
			}
		}
		delete[] buckets;
	}

	// Funkcja sortuj¹ca dokumenty leksykograficznie po symbolach tematu
	void sort_by_subject_symbols() {
		for(short i = 3; i >= 0; i--) {
			std::vector<Document*> buckets[257];
			for(auto& doc : documents) {
				buckets[doc->subject_symbols[i] + 1].push_back(doc);
			}
			uint pos = 0;
			for(ushort j = 0; j < 257; j++) {
				for(auto& doc : buckets[j]) {
					documents[pos++] = doc;
				}
			}
		}
	}

public:

	// Konstruktor wczytuj¹cy dane bezpoœrednio do postaci posortowanej bo unikalnych numerach dokumentów
	DocumentSorter(uint nof_documents) {
		documents.resize(nof_documents);
		for(uint i = 0; i < nof_documents; i++) {
			uint unique_number;
			ushort priority;
			uint random_code;
			ushort nof_subject_symbols;
			std::cin >> unique_number >> priority >> random_code >> nof_subject_symbols;
			// Wstawienie dokumentu bezpoœrednio do odpowiedniego miejsca w wektorze, aby by³ on od razu posortowany
			documents[unique_number - 1] = new Document(unique_number, priority, random_code, nof_subject_symbols);
		}
		for(ushort i = 0; i < 4; i++) {
			ushort sorting_parameter;
			std::cin >> sorting_parameter;
			if(sorting_parameter == 1) break;
			// Poniewa¿ zawsze sortowanie zaczynaæ bêdzie siê od 1, jest ona wykonana bezpoœrednio przy wczytaniu danych
			sorting_order.push_front(sorting_parameter);
		}
	}

	// Funkcja sortuj¹ca dokumenty zgodnie z kolejnoœci¹ sortowania
	void sort() {
		for(auto& sorting_parameter : sorting_order) {
			switch(sorting_parameter) {
				// sortowanie 1 wykonane jest przy wczytywaniu danych
			case 2:
				sort_by_priority();
				break;
			case 3:
				sort_by_random_code();
				break;
			case 4:
				sort_by_subject_symbols();
				break;
			}
		}
	}

	// Funkcja zwracaj¹ca sumê losowych kodów pomno¿onych przez indeks dokumentu modulo 100,000,007
	uint result() {
		uint result = 0;
		for(uint i = 0; i < documents.size(); i++) {
			result = (result + (ulong)documents[i]->random_code * i) % 100000007;
		}
		return result;
	}

	// Destruktor
	~DocumentSorter() {
		for(auto& doc : documents) {
			delete doc;
		}
	}

};

int main() {
	std::ios_base::sync_with_stdio(false);

	uint n; // Liczba dokumentów

	std::cin >> n;

	DocumentSorter sorter(n); // Obiekt sortuj¹cy

	sorter.sort(); // Sortowanie

	std::cout << sorter.result() << std::endl; // Wyœwietlenie rezultatu

	return 0;
}