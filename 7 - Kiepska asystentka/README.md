# Kiepska asystentka

Spotkanie z informatorem zaowocowało dalszym planem działań. Partycja dostała namiary na ludzi, którzy mogli wiele wnieść do śledztwa. Zauważyła jednak, że czasem daną osobę warto jest odwiedzić wcześniej niż inne, bo może mieć informacje przydatne w kolejnych rozmowach. Poprosiła swoją główną asystentkę, by sporządziła jej propozycje planów wizyt na podstawie ustawionych przez Partycję priorytetów. Nasz bohaterka otrzymała już plany, ale ma podejrzenie, że asystentka nie zrobiła tego jak należy. Woli więc sprawdzić, czy jej lista zgadza się z ustalonymi wcześniej priorytetami.

## Wejście
W pierwszej linii wejścia znajduje się liczba naturalna **t**, czyli liczba zestawów danych. Każdy zestaw danych składa się z dwóch liczb naturalnych **n** oznaczającej liczbę nazwisk i **m** oznaczającej liczbę par nazwisk. W kolejnych **n** liniach znajduje się lista wszystkich nazwisk jako jednowyrazowe łańcuchy znaków. W dalszych **m** liniach znajdują się pary nazwisk. Każda para oznacza, że pierwszą osobę z pary należy odwiedzić wcześniej niż drugą osobę z pary.

W ostatniej linii zestawu znajduje się lista nazwisk, oznaczająca proponowaną przez asystentkę kolejność.

```
**1 ≤ t ≤ 10**<br>
**1 ≤ n ≤ 1000000**
```
## Wyjście
Na wyjściu dla każdego zestawu danych należy wypisać słowo **TAK**, jeżeli proponowana kolejność jest zgodna z założeniami lub **NIE** w przeciwnym wypadku.

## Przykład
### Wejście:
```
2
6 5
Abramczyk 
Bednarski
Cajzer
Dzik
Elert
Frackowiak
Abramczyk Bednarski
Abramczyk Cajzer
Bednarski Dzik
Elert Frackowiak
Cajzer Dzik
Elert Abramczyk Frackowiak Cajzer Bednarski Dzik
6 5
Abramczyk 
Bednarski
Cajzer
Dzik
Elert
Frackowiak
Abramczyk Bednarski
Abramczyk Cajzer
Bednarski Dzik
Elert Frackowiak
Cajzer Dzik
Elert Frackowiak Bednarski Cajzer Abramczyk Dzik
```

### Wyjście:
```
TAK
NIE
```