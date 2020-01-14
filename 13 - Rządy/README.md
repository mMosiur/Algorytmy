# Rządy

Partycja ostatnio zastanawia się, które rządy wiedzą o zbliżającej się katastrofie. Postanowiła na podstawie zdobytych informacji zrobić zestawienie mające wytypować, które państwa wiedzą, a które nie wiedzą o katastrofie. Każdemu państwu przypisywany jest współczynnik będący liczbą całkowitą z zakresu od 0 do 1000000 mówiący o tym jak bardzo pewne jest, że rząd danego państwa wie o czekającej ziemię katastrofie. Partycja wraz ze współpracownikami z całego świata aktualizuje współczynniki przypisane poszczególnym państwom po uzyskaniu nowych informacji. Na przykład fakt, że jakiś rząd blokuje porozumienie klimatyczne albo składa nierealne obietnice socjalne jest dla niej argumentem za tym, że ten rząd wie iż od września 2020 roku żadne obietnice nie będą miały znaczenia (pojawienie się tego typu informacji powoduje zwiększenie współczynnika przypisanego danemu państwu). Z kolei jeżeli jakiś rząd prowadzi odpowiedzialną politykę, wprowadza oszczędności budżetowe itp. jest to dla Partycji poszlaką świadczącą o tym, że dany rząd nie wie nic o zbliżającej się katastrofie (co zmniejsza wartość współczynnika przypisanego danemu państwu).

Partycja uruchomiła działający w Darknecie serwer umożliwiający wolontariuszom z całego świata aktualizację współczynników na podstawie zdobytych przez nich dokumentów. Wraz ze wzrostem liczby wolontariuszy stary serwer zaczął się ,,zapychać''. Partycja postanowiła oszacować potrzeby przed zakupem nowego. W tym celu zaczęła zliczać operacje wykonywane na serwerze. Ponieważ lista państw jest przechowywana w kopcu binarnym posortowanym względem rozważanego współczynnika to Partycja postanowiła zliczać liczbę zamian ojca z synem w trakcie przesiewania w kopcu. Kopiec jest zaimplementowany w taki sposób, że w trakcie przesiewania w dół, w przypadku gdy obaj synowie przesiewanego wierzchołka mają równą wartość współczynnika, wierzchołek zamieniany jest z tym z synów, który znajduje się w komórce tablicy o mniejszym indeksie. Ze względów konspiracyjnych państwom przypisano liczby z przedziału od 0 do 1000, które są używane zamiast ich nazw.

## Wejście

Na wejściu program otrzymuje liczbę **n** rozważanych państw a następnie **n** opisów państw w kolejności w jakiej odpowiadające tym państwom węzły znajdują się w tablicy przechowującej kopiec. Opisy poszczególnych państw składają się z par **p**, **w** liczb oznaczających kolejno numer przypisany do państwa oraz jego współczynnik. Następnie program otrzyma liczbę **m** oraz **m** opisów zmian rozważanego współczynnika. Każdy opis składa się z pary **p**, **w** oznaczającej, że współczynnik państwa **p** otrzymuje nową wartość **w**.
```
1<=n<=1000
1<=m<=2000000
```

## Wyjście

Na standardowym wyjściu program powinien wypisać liczbę zamian wykonanych w trakcie przesiewania elementów kopca.

## Przykłady

### Wejście
```
4
48 1000
1 999
7 999
44 997
3
48 996
1 1001
7 995
```

### Wyjście
```
2
```

### Wejście
```
4
48 1000
1 999
7 999
44 997
2
7 995
48 1001
```

### Wyjście
```
0
```

### Wejście
```
4
48 1000
1 999
7 999
44 997
3
48 998
44 1000
1 1001
```

### Wyjście
```
4
```