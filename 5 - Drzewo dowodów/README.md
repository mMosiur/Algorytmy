# Drzewo dowodów

Grupa operacyjna Partycji (którą udało się skompletować w ostatnim czasie) działała bardzo prężnie i każdego dnia wprowadzała do ich współdzielonego arkusza kalkulacyjnego dane o nowych materiałach dowodowych. Umówili się na dokładne kategoryzowanie danych i przykładowy wpis do arkusza wyglądał następująco:

"Kategoria 1 - Podkategoria 4 - Rodzaj 2 - Typ 7 - Wpis 2" lub "Kategoria 3 - Podkategoria 2 - Rodzaj 6" czy też "Kategoria 3 - Podkategoria 2 - Rodzaj 3" co w skrócie można zapisać jako: 1 4 2 7 2 dla pierwszego przykładu, 3 2 6 dla drugiego przykładu i 3 2 3 dla trzeciego przykładu.

Danych było coraz więcej i śledczy zaczęli się coraz bardziej gubić. Partycja doszła do wniosku, że dużo lepiej wyglądałoby to w formie drzewa, takiego jak poniżej.

```
          0
         / \
        1   3
       /     \
      4       2
     /       / \
    2       6   3
   /
  7
 /
2
```

Potrzebowała więc małego systemu, który na podstawie ponumerowanych i skategoryzowanych wpisów umieszczałby poszczególne wartości w odpowiednim miejscu drzewa materiałów dowodowych. Zakładamy, że korzeń drzewa ma numer 0 i od niego zaczynają się wszystkie wpisy.

## Wejście
W pierwsze linii wejścia znajduje się liczba naturalna **n** oznaczająca liczbę wpisów w arkuszu materiałów dowodowych. W kolejnych **n** liniach znajdują się wpisy. Każdy wpis składa się z liczby naturalnej **x**, po której następuje **x** liczb, tworzących wpis.

**1 ≤ n ≤ 10000
1 ≤ x ≤ 10000**

## Wyjście
Na wyjściu należy wyświetlić tak zbudowane drzewo w kolejności preorder. Korzeń o wartości "0" należy na wyjściu pominąć.

**UWAGA! W zadaniu nie można używać bibliotek STL.**

## Przykład
Wejście:
```
10
5 3 1 5 2 7
4 3 1 2 6
3 3 4 1
2 5 6
3 2 6 7
3 2 6 8
3 2 5 6
1 1
1 3
2 1 3 
```
Wyjście:
```
3 1 5 2 7 2 6 4 1 5 6 2 6 7 8 5 6 1 3
```