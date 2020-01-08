# Wolontariusze

Problemy z przekazaniem dokumentów od eksperta sprawiły, że Partycja postanowiła obsadzić stacje kolejowe współpracującymi z nią wolontariuszami w taki sposób, żeby każdy pociąg musiał przejeżdżać przez co najmniej jedną stację, na której wolontariusz mógłby odebrać dokumenty od kuriera. Oznacza to, że na co najmniej jednym końcu każdego odcina torów łączącego dwie stacje musi być wolontariusz. Oczywiście do obsadzenia wszystkich końców znajdujących się na jednej stacji wystarczy jeden wolontariusz. Niestety liczba wolontariuszy współpracujących z Partycją jest mocno ograniczona. Partycja zastanawia się czy ich liczba jest wystarczająca do obsadzenia końców wszystkich odcinków linii kolejowych.

## Wejście:

Pierwsza linia wejścia zawiera liczbę całkowitą **t** - liczbę zestawów danych, których opisy występują kolejno po sobie. W pierwszej linii zestawu danych podane są trzy liczby naturalne **n**, **m** i **r** - odpowiednio liczba stacji kolejowych , liczba odcinków kolejowych bezpośrednio łączących ze sobą dwie stacje kolejowe oraz liczba wolontariuszy. Każda z kolejnych **m** linii zawiera dwie liczby naturalne **a** i **b** - numery stacji kolejowych połączonych bezpośrednim odcinkiem torów.

**1 ≤ t ≤ 150**<br>
**1 ≤ n ≤ 30**<br>
**1 ≤ m ≤ 100**<br>
**1 ≤ r ≤ 20**<br>
**1 ≤ a, b ≤ n**<br>

## Wyjście:

Dla każdego zestawu danych program powinien wypisać jedną linię zawierającą napis
```
TAK
```
, jeśli liczba wolontariuszy jest wystarczająca albo
```
NIE
```
w przeciwnym przypadku.

### Przykładowe wejście:
```
3
2 1 1
1 2
4 6 2
1 2
1 3
1 4
2 3
2 4
3 4
6 1 1
4 5
```

### Przykładowe wyjście:
```
TAK
NIE
TAK
```

Zadanie należy rozwiązać za pomocą przeszukiwania z nawrotami.