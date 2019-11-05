# Eksperyment

Partycja postanowiła włączyć się do pewnej akcji. Grupa jej przyjaciół prowadzi eksperyment nad wydajnością badań grupy naukowców. Obecnie pracują nad nowymi metodami walki z globalnym ociepleniem. Ponieważ katastrofa może nastąpić lada moment trzeba działać szybko. Badacze muszą zostać rozdzieleni na dwie grupy pracujące równolegle. Okazuje się, że właśnie to jest kluczową sprawą dla wydajności. Partycja otrzymała listę naukowców składającą się z imienia, nazwiska oraz punktów zdolności badawczych. Im punktacja jest wyższa tym zdolniejszy jest dany naukowiec. Badacze są jednak niezwykle przywiązani do swoich miejsc. Siedzą przy okrągłym stole zawsze w takiej samej kolejności jaki prezentuje lista. Partycja musi ich podzielić na dwie równe grupy. Należy jednak pamiętać, że różnica między najzdolniejszym oraz najmniej zdolnym naukowcem powinna być jak najmniejsza i absolutnie nie może przekraczać ściśle określonej wartości. Mogłoby to spowodować konflikty w zespole. Ważniejsze są jednak średnie zdolności każdego zespołu która powinny być możliwie najrówniejsze. Zawsze może się zdarzyć sytuacja w której zespół można podzielić na więcej niż jeden sposób dlatego nasza bohaterka musi wykonać swoją pracę zgodnie ze ściśle określoną procedurą. Podzieli stół na dwie równe połowy względem otrzymanej listy. Następnie będzie przesuwała się o jedną osobę zgodnie z kierunkiem ruchu zegara. Pierwsze najlepsze rozwiązanie zostaje uznane za właściwy podział. Co ważne liczba naukowców zawsze jest parzysta. Ponieważ pracę należy wykonywać codziennie bo pracownicy często się zmieniają Partycji przydałby się program który zautomatyzuje pracę.

## Wejście:
W pierwszej linii wejścia program otrzymuje liczbę **n** oznaczającą ilość naukowców oraz **v** będącą maksymalną różnicą zdolności naukowców w zespole. Następnie w n liniach program otrzymuje dane naukowców zgodnie z ruchem wskazówek zegara, składające się z dwóch ciągu znaków **f** oraz **s** będących imieniem i nazwiskiem naukowca oraz liczbę naturalną **i** oznaczającą zdolność.

## Wyjście:
Na wyjściu program powinien wyświetlić dwie listy naukowców oddzielone spacją. Listy powinny być wyświetlone w kierunku zgodnym z kierunkiem wprowadzania. Jeżeli naukowców nie da się podzielić zgodnie z wytycznymi należy wyświetlić słowo „NIE”.

**1 ≤ n ≤ 100000**
**1 ≤ i ≤ 1000**

### Przykładowe wejście:
```
6 5
Jan Nowak 12
Wojciech Kowalski 11
Irena Krawiec 1
Marcin Janowski 3
Krystian Król 2
Joanna Malinowska 10
```

### Przykładowe wyjście:
```
Irena Krawiec
Marcin Janowski
Krystian Król

Joanna Malinowska
Jan Nowak
Wojciech Kowalski
```

**Uwaga:**
**Rozwiązanie ma wykorzystywać samodzielną implementację kolejki bez wykorzystania bibliotek STL.**