# Informator

Do siedziby operacyjnej Partycji dotarła wiadomość od jednego z jej tajnych informatorów. Miał do przekazana bardzo obiecujące informacje, który mogły w znacznym stopniu przyczynić się do ujawnienia rządowego spisku. Podał miejsce spotkania, jednak zastrzegł, by po mieście poruszać się z dużą ostrożnością i unikać monitorowanych miejsc.

Partycja zaczęła studiować mapę miasta, o wymiarach **n**x**m**. Podzieliła ją na **n** rzędów i **m** kolumn, a każdy tak powstały fragment mapy oznaczyła w następujący sposób:
```
. - miejsce z możliwością przejazdu
\# - miejsce zablokowane bez możliwości przejazdu
M - miejsce z możliwością przejazdu, monitorowane
S - siedziba operacyjna
X - miejsce spotkania
```
Na początku postanowiła wyznaczyć najkrótszą drogę z siedziby do miejsca spotkania i sprawdzić ile miejsc monitorowanych się na tej drodze znajduje. Przez najkrótszą drogę rozumiana jest liczba miejsc odwiedzonych pomiędzy siedzibą a miejscem spotkania. Po mapie z danego miejsca można się poruszać na sąsiadujące pola w górę, w dół, lewo lub prawo (o ile pola te nie są zablokowane). W przypadku znalezienia więcej niż jednej najkrótszej drogi o tej samej długości, pierwszeństwo ma ta z mniejszą liczbą miejsc monitorowanych.

## Wejście
W pierwszej linii wejścia znajdują się dwie liczby naturalne **n** i **m**, oznaczające wymiary mapy. W kolejnych liniach znajduje się reprezentacja mapy zgodna z opisem. Należy przyjąć, że zawsze istnieje droga prowadząca od siedziby do miejsca spotkania.

**1 ≤ n,m ≤ 1000**

## Wyjście
Na wyjściu program ma wypisać dwie liczby naturalne oznaczające długość najkrótszej drogi do punktu docelowego oraz liczbę napotkanych miejsc monitorowanych.

## Przykład
Wejście:
```
5 8
#..M.M#X
S..##...
.#.M...#
...#.#.#
####..M#
```

## Wyjście:
```
10 1
```
