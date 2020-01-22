# Rządy c.d.

Partycja od kilku tygodni nie robi nic innego tylko porządkuje, sortuje itp. Powoli zaczyna mieć tego dość. Dobrze, że chociaż analiza planów różnych rządów bywa zabawna (choć to słowo wydaje się być nie do końca na miejscu w obecnej sytuacji), gdy pamięta się, że świat jaki znamy skończy się we wrześniu 2020. Partycja zapisuje co lepsze przykłady działań rządów. Przykładowo niedawno jeden z rządów zaproponował swoim obywatelom wykup stuletnich nieoprocentowanych obligacji. W zamian posiadacze obligacji mieliby brać udział w losowaniach cennych nagród. Pierwsze losowanie w październiku 2020 - dopowiedziała w myślach Partycja. Także dopiero teraz dotarło do Partycji dlaczego przyznano Katarowi mistrzostwa świata w piłce nożnej, które mają się odbyć w 2022 roku. Równie dobrze można by je zorganizować na Antarktydzie - pomyślała Partycja.

Znudzona porządkowaniem dokumentów Partycja postanowiła poprosić znajomego informatyka o dodanie do serwisu monitorującego działalność rządów poszczególnych krajów jeszcze jednej funkcjonalności. Chodzi o wyszukiwanie dla podanego **k** państwa o **k**-tej wartości współczynnika określającego stopień pewności, że rząd danego państwa wie o nadchodzącej katastrofie.

## Wejście

Na wejściu program otrzymuje liczbę **n** rozważanych państw a następnie **n** opisów państw w losowej kolejności. Opisy poszczególnych państw składają się z par **p**, **w** liczb oznaczających kolejno numer przypisany do państwa oraz jego współczynnik (numer państwa jest unikalną liczbą z zakresu od 0 do 10000000). Następnie program otrzyma liczbę **m** oraz **m** zapytań. Każde zapytanie składa się z liczby z zakresu od 1 do **n**.
```
1<=n<=500000
1<=m<=200
```

## Wyjście

Na standardowym wyjściu program powinien wypisać odpowiedzi dla wszystkich zapytań. Dla zapytania **k** powinien wypisać numer kraju o **k**-tej wartości badanego współczynnika. Zakładamy, że przy takich samych wartościach współczynnika wypisywany jest najmniejszy spośród numerów państw o tym współczynniku.

## Przykłady

### Wejście
```
4
7 999
48 1000
1 999
44 997
4
1
2
3
4
```

### Wyjście
```
44
1
1
48
```

### Wejście
```
4
48 1000
1 1000 
7 1000
44 1000
3
4
1
2
```

### Wyjście
```
1
1
1
```

### Wejście
```
1
48 1000
1
1
```

### Wyjście
```
48
```

**Uwaga** program powinien działać w oczekiwanym czasie liniowym.