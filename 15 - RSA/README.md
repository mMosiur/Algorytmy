# RSA

W pracy każdego dziennikarza śledczego bardzo ważna jest konspiracja. Szczególnie ważne jest to w przypadku dziennikarza prowadzącego śledztwo w sprawach w które zamieszane są agencje rządowe. Wiadomo, że państwo ma wiele narzędzi, żeby takiego dziennikarza zniszczyć. Władza za pośrednictwem osób trzecich (na przykład żony ministra) może zarządzać niepublikowania tekstów takiego dziennikarza w mediach pod groźbą wycofania reklam spółek skarbu państwa z tych mediów. Może też oczernić go w rządowej telewizji wykorzystując ,,przecieki'' z organów ścigania (na przykład o policyjnej notatce, że dziennikarz w młodości był widywany w stanie nietrzeźwym i co więcej mieszkał w tym samym akademiku co studenci filologii rosyjskiej). W skrajnym przypadku taki dziennikarz może być aresztowany i pod zarzutem przyjęcia korzyści o dużej wartości (na przykład zegarka produkcji japońskiej) w zamian za opublikowanie artykułów wychwalających zalety jednego nadmorskiego kurortu ponad zalety innego kurortu (na podstawie zeznań skruszonego burmistrza pierwszego kurortu).

Aby dochować zasad konspiracja Partycja postanowiła w korespondencji ze swoimi współpracownikami używać szyfru RSA. Partycja nie ufa jednak powszechnie używanym implementacjom tego szyfru gdyż za dobrze pamięta aferę z OpenSSL-em. W związku z tym potrzebuje między innymi programu, który na podstawie liczb pierwszych **p** i **q**, których iloczyn jest równy **n** (wszystkie obliczenia w wykonywane są modulo **n**) oraz klucza publicznego **e** wygeneruje klucz prywatny **d** i rozszyfruje zaszyfrowaną wiadomość **c**.

## Wyjście

Na standardowym wyjściu program otrzyma liczbę zestawów danych **t** a następnie **t** zestawów zawierających liczby **p**, **q**, **e** oraz **c**.

```
1<=n<4294967296<br>
p,g,e,c< n
```

## Wyjście
Dla każdego zestawu danych wypisz rozszyfrowaną wiadomość.

## Przykłady

### Wejście
```
5
2 5 3 3
3 5 9 4
13 17 5 11
19 3 7 55
7 5 11 22
```

### Wyjście
```
7
4
7
16
8
```

**Uwaga** program powinien używać własnych implementacji algorytmów Euklidesa i potęgowania metodą wielokrotnych kwadratów.