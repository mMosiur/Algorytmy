# Œledzona

Od pewnego czasu Partycja mia³a wra¿enie, ¿e ktoœ j¹ œledzi. Kiedy przechadza³a siê po mieœcie wrêcz czu³a spojrzenia tajnych agentów. Nawet we w³asnym mieszkaniu czu³a siê nieswojo. Zaczê³a siê zastanawiaæ czy przypadkiem ktoœ nie umieœci³ urz¹dzeñ pods³uchuj¹cych w jej lokum. Uda³a siê do swojego przyjaciela który wrêczy³ jej detektor pluskiew. Urz¹dzenie jest w stanie okreœliæ iloœæ pods³uchów w pokoju oraz wskazaæ kierunek do ka¿dego z nich z dowolnego punktu w formie kierunków geograficznych. Partycja obawia siê, ¿e je¿eli rozpocznie poszukiwania osobiœcie, wzbudzi tym czujnoœæ agentów. Postanowi³a zatem wykorzystaæ do tego celu robota jednak potrzebuje odpowiedniego oprogramowania.

## Wejœcie

Na wejœciu program otrzymuje trzy liczby naturalne. Pierwsze dwie opisuj¹ rozmiary mieszkania Partycji w postaci dwóch liczb **x** oraz **y**. Ostatnia liczba to iloœæ poszukiwanych pluskiew **t**. Do lokalizacji nale¿y wykorzystaæ funkcjê wbudowan¹ **std::string test(unsigned &x, unsigned &y, unsigned &id)**. Dwie pierwsze zmienne to wspó³rzêdne robota w pokoju natomiast ostatnia to numer poszukiwanej pluskwy numerowana od 0 do t-1. Funkcja zwraca jeden z oœmiu kierunków geograficznych (_N_, _NE_, _E_, _SE_, _S_, _SW_, _W_, _NW_) okreœlaj¹ce w któr¹ stronê nale¿y siê poruszyæ, ¿eby znaleŸæ poszukiwany punkt. Je¿eli pods³uch znajduje siê w testowanym punkcie, funkcja zwróci pusty ci¹g znaków.

## Wyjœcie

Na wyjœciu program powinien wyœwietliæ lokalizacjê wszystkich pluskiew zgodnie z rosn¹c¹ numeracj¹ id funkcji test.

```
**0 < x ? 2000000000**
<br>
**0 < y ? 2000000000**
<br>
**0 < t ? 100000**
```

### Przyk³adowe wejœcie

```
20 20 2
```

### Przyk³adowe wyjœcie
```
5 5
14 16
```

**Program przesy³any na sprawdzarkê _nie mo¿e zawieraæ_ funkcji test! Zostanie ona automatycznie do³¹czona przez system do rozwi¹zania i jest charakterystyczna dla ka¿dego z testów.**<br>

Funkcja w przyk³adzie jest zdefiniowana nastêpuj¹co:
```
std::string test(unsigned &x, unsigned &y, unsigned &id) {
    unsigned xTest, yTest;
    std::string direction = "";
    switch( id ) {
    case 0:
        xTest = 5;
        yTest = 5;
        break;
    case 1:
        xTest = 14;
        yTest = 16;
        break;
    default:
        xTest = 0;
        yTest = 0;
        break;
    }
    if(yTest < y)
        direction = "S";
    else if(yTest > y)
        direction = "N";
    if(xTest < x)
        direction += "W";
    else if(xTest > x)
        direction += "E";
    return direction;
}
```