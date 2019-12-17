# Upadek mediów

Partycja przeczytała analizę obietnic wyborczych stworzoną przez niezależnego eksperta. Wnioski były porażające, ale to co ją najbardziej zatrwożyło, to pojawiający się na marginesie raporto temat upadku dziennikarstwa. Okazało się, że tak na prawdę nikt nie próbuje kontrolować rządzących. Głównym zajęciem większości redakcji jest przepisywanie informacji podanych przez innych. Dochodzi do tego, że jedna redakcja potrafi podawać tą samą informację wielokrotnie za każdym razem przepisując ją z innego źródła. W najbardziej skrajnych przypadkach gazety potrafiły przepisywać informacje pochodzące pierwotnie z nich samych. W takim gąszczu cytowań trudno dojść, które informacje są prawdziwe, a które nie. Ten mechanizm nauczyły się wykorzystywać rządy podrzucając wybranym redakcjom materiały przepisywane potem przez inne redakcje. Jedną z ofiar takich działań stała się Partycja, która już zdążyła nadepnąć na odcisk rządzącym. ,,Anonimowy'' informator podsunął jednemu z internetowych portali rzekomy post z 2013 roku o tancerce Partycji z pewnego klubu, która przyjęła oświadczyny klienta. W poście nie było niby informacji o nazwisku tancerki, ale przecież wiadomo, że na świecie jest tylko jedna Partycja. Bardzo to zdenerwowało Partycję, gdyż w jej zawodzie zaufanie jest kluczowym zagadnieniem, a tego typu informacje mogą podważyć zaufanie do jej profesjonalizmu u potencjalnych informatorów.

Partycja zaobserwowała, że istnieją pewne regularności w przepisywaniu wiadomości. Na przykład wtorkowa moskiewska Najprawdziwsza Prawda przepisuje wiadomości z poniedziałkowej Prawdy, a czwartkowy warszawski Kurier Niezależny lubi powtarzać wiadomości z wtorkowej Gazety Niezależnej Codziennie. Analizując prasę z całego świata Partycja stworzyła ,,graf cytowań''. Teraz chce przewidywać jak rozprzestrzeni się po upływie określonego czasu informacja przekazana konkretnej redakcji w konkretnym dniu. Wiadomo, że redakcje każdego dnia przepisują informacje z wybranych wydań określonych gazet, programów itp. Wiadomo, że wybrane wydania pochodzą z 6 dni poprzedzających opublikowanie informacji. Zakładamy, że kopiowanie zachodzi automatycznie (a więc przykładowo jeżeli wtorkowa Najprawdziwsza Prawda przepisuje informacje z poniedziałkowej Prawdy, to dotyczy to każdej informacji w każdym tygodniu). Oczywiście z braku miejsca i czasu nie wszystkie informacje da się przepisać jednak nie ma możliwości przewidzenia, które informacje się nie zmieszczą. Dlatego Partycja chce szacować na ile różnych sposobów informacja ma szansę dotrzeć do odbiorcy (czyli liczbę różnych ścieżek w ,,grafie cytowań'' startujących w określonym punkcie i kończących się przed upływem określonego czasu).

## Wejście

Na wejściu program otrzymuje pięć liczb **n**,**s**,**d**,**l**,**m** oznaczające kolejno liczbę analizowanych mediów (media numerujemy od 0 do **n**-1), medium, które jako pierwsze otrzymało informację, dzień tygodnia kiedy tą informację opublikowano (dzień tygodnia jest liczbą z zakresu od 0 do 6 oznaczającą numer dnia tygodnia), liczbę dni kiedy informacja rozprzestrzeniała się po mediach oraz liczbę krawędzi w ,,grafie cytowań''. Następnie program otrzyma **m** czwórek liczb postaci **a**, **b**, **c**, **d** oznaczających, że gazeta **a** cytuje w dniu **b** informacje z gazety **c** z dnia **d**.
```
1<=n<=300
1<=m<=2000
1<=l<=100000
```

## Wyjście

Na standardowym wyjściu program powinien wypisać liczbę wszystkich ścieżek w grafie cytowań zaczynających się w wierzchołku **s** w dniu tygodnia **d** w których ostatni wierzchołek reprezentuje publikację rozważanej informacji przed końcem **d**-tego dnia. Wynik powinien zostać wypisany modulo 100000007.

## Przykłady

### Wejście
```
3 1 3 3 5
0 3 1 1
0 4 1 3
2 4 1 3
1 5 2 4
2 5 1 4
```

### Wyjście
```
4
```

### Wejście
```
3 1 3 2 5
0 3 1 1
0 4 1 3
2 4 1 3
1 5 2 4
2 5 1 4
```

### Wyjście
```
3
```

**UWAGA** rozwiąż problem przy pomocy programowania dynamicznego.