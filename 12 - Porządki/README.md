# Porządki

Sylwestra Partycja spędziła w domu. Nie miała ochoty iść tego dnia na jakąkolwiek imprezę. No bo czego miałby życzyć innym o północy? Szczęśliwych ostatnich dziewięciu miesięcy ludzkiej cywilizacji? Nie, Partycja zdecydowanie nie miała na to ochoty. Postanowiła posegregować zebrane do tej pory akta prowadzonego przez nią śledztwa.

Wszystkie dokumenty zebrane przez Partycję mają swoj unikalne numery (od 1 do **n**, gdzie **n** jest liczbą dokumentów), priorytety (liczba całkowita z zakresu od 0 do 10), losowe kody z zakresu od 0 do 10000000 (niekoniecznie unikalne) oraz zostały oznaczone symbolami tematyki dokumentu (maksymalnie 4 liczby z zakresu od 0 do 255 uporządkowane od symbolu najbardziej istotnego do najmniej istotnego, czasami przez pomyłkę ten sam symbol może wystąpić wielokrotnie, ale Partycji nie chce się tego poprawiać). Partycja chce móc sortować dokumenty:

1. rosnąco po numerach,
2. rosnąco po priorytetach,
3. rosnąco po kodach,
4. leksykograficznie względem listy kodów tematów (w pierwszej kolejności porównuje symbole najbardziej istotne na poszczególnych listach, potem drugie itd., jeżeli jakiś ciąg symboli jest początowym podciągiem innego, to jest wcześniej w kolejności lekykograficznej)

Partycja, chciałaby móc sortować po wszystkich wyżej wymienionych parametrach, ale przy różnym uszeregowaniu ważności poszczególnych prametrów (na przykład w pierwszej kolejności po priotytetach, w drugiej po kodach itd.).

## Wejście
Na wejściu program otrzymuje liczbę **n**, a następnie **n** opisów dokumentów. Opis każdego z dokumentów składa się z unikalnego numeru, priorytetu, losowego kodu, liczby **m** kodów tematów dotyczących danego dokumentu (z zakresu od 1 do 4) a następnie **m** liczb z zakreso do 0 do 255. Na końcu program otrzyma liczby 1, 2, 3 i 4 odpowiadające kolejno numerom, priorytetom, kodom dokumentów oraz kodom tematów uporządkowane względem ich wagi przy sortowaniu.
```
1<=n<=2000000
```

## Wyjście
Na standardowym wyjściu program powinien wypisać sumę losowych kodów poszczególnych dokumentow pomnożonych przez finalny indeks elementu w posortowanej tablicy. Wynik powinien zostać wypisany modulo 100000007.

## Przykłady
### Wejście
```
5
2 10 145 2 0 1
4 2 1119 4 255 0 1 2
1 10 0 2 0 1
3 5 2 4 255 0 1 2
5 10 99999 1 24
4 2 3 1
```
### Wyjście
```
203508
```
### Wejście
```
5
2 10 145 2 0 1
4 2 1119 4 255 0 1 2
1 10 0 2 0 1
3 5 2 4 255 0 1 2
5 10 99999 1 24 
4 3 2 1
```
### Wyjście
```
204625
```
### Wejście
```
1
1 10 0 2 0 1
1 2 3 4
```
### Wyjście
```
0
```
**UWAGA** rozwiąż problem przy pomocy samodzielnie zaimplementowanych algorytmów sortujących w czasie liniowym.