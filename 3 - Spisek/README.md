# Spisek

Partycja odkryła straszną prawdę. Światem od wieków rządzą tajne organizacje. Nasza bohaterka uwielbia demaskować ich tajemnice. Podobno na odwrocie deklaracji podległości spisanej przez samych ojców stworzycieli jest zapisany szyfr. Dotarcie do niego zajęło naszej bohaterce nieco czasu. Wykorzystując znajomości udało się jej otrzymać tajną fotografię dokumentu od konserwatorki. Oczom Partycji ukazał się jednak dziwny zestaw słów oraz cyfr. Postanowiła, że ze swoim problemem uda się do znanego historyka specjalizującego się w starych szyfrach. Specjalista przyjrzał się dokumentowi i rzekł:

\- Widziałem już kiedyś taki szyfr. Używały go tajne organizacje wiele lat temu. Jak widzisz mamy dwa zestawy słów. Pierwszy składa się z par zbudowanych z jednego słowa oraz liczby. Dla ułatwienia liczbę z pary będziemy nazywać wartością słowa. Poruszamy się po liście słów przechodząc od jednego do następnego, dodając je do zdania wynikowego. Wartość w parze oznacza o ile słów od obecnego należy się przesunąć. Jeżeli jest ona dodatnia poruszamy się zgodnie z kierunkiem wprowadzania. Gdyby jednak wartość była ujemna poruszamy się w kierunku przeciwnym. Jeżeli dotrzesz do końca listy przeglądanie rozpoczynasz z drugiej strony. Pamiętaj jednak, że każde słowo może być użyte tylko raz. Przeglądanie powinno zostać rozpoczęte od ustalonego numerem słowa.

\- Więc do czego jest ta druga lista słów?

\- Jeżeli podczas przeglądania pierwszej listy trafisz na słowo którego wartość jest równa 0 to zamiast dodawać ją do wynikowego zdania należy dodać nowe słowo do listy jako poprzednik obecnie znalezionego zgodnie z kierunkiem wprowadzania. Pobiera się je właśnie z tej drugiej listy. Ponieważ nie zostało jeszcze wykorzystane nie powinno być usuwane. Musisz pamiętać, żeby zmodyfikować wartość znalezionego słowa. Jak widzisz lista słów oczekujących na dodanie oprócz pary ma dodatkową liczbę. To wartość która zastąpi znalezione 0. Na koniec wyszukujesz nowe słowo przemieszczając się właśnie o tą zmodyfikowaną wartość. Możesz być pewna, że ilość słów dodatkowych zawsze jest wystarczająca. Ba, zwykle jest ich nawet za dużo. Wyszukiwanie kończy się kiedy skończą się elementy w pierwszej liście.

Partycja miała już plan. Zostało zatem tylko odczytać szyfr …

## Wejście:
Na wejściu program otrzymuje liczbę **n** oznaczającą rozmiar listy słów oraz **s** będącą numerem słowa startowego. Następnie w n liniach program otrzymuje parę składającą się z pojedynczego słowa **s** oraz liczby **x**. W kolejnym kroku podawana jest liczba **p**, która określa ilość słów oczekuje na dodanie. Następnie w p liniach program otrzymuję listę oczekujących par **s** oraz **x** oraz **y**, gdzie ostatnia wartość jest liczbą zastępującą 0 które spowodowało dodanie nowego elementu.

## Wyjście:
Na wyjściu program powinien wypisać odtworzone zdanie. Działanie kończy się kiedy cała lista zostanie opróżniona.

**1 ≤ n ≤ 30000 <br>
0 ≤ p ≤ 30000 <br>
-1000000 ≤ x, d ≤ 1000000**

## Przykładowe wejście:
```
7 5
spadaniem 5
czestym 0
kamien 7
drazy -2
sila 2
Kropla -2
nie -1
3
lecz 1 -5
tak 8 2
syzbko -9 6
```
## Przykładowe wyjście:
```
Kropla drazy kamien nie sila lecz czestym spadaniem
```
**Uwaga:**
**Rozwiązanie ma być samodzielną implementacją list bez wykorzystania bibliotek STL.**