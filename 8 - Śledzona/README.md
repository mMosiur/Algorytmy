# �ledzona

Od pewnego czasu Partycja mia�a wra�enie, �e kto� j� �ledzi. Kiedy przechadza�a si� po mie�cie wr�cz czu�a spojrzenia tajnych agent�w. Nawet we w�asnym mieszkaniu czu�a si� nieswojo. Zacz�a si� zastanawia� czy przypadkiem kto� nie umie�ci� urz�dze� pods�uchuj�cych w jej lokum. Uda�a si� do swojego przyjaciela kt�ry wr�czy� jej detektor pluskiew. Urz�dzenie jest w stanie okre�li� ilo�� pods�uch�w w pokoju oraz wskaza� kierunek do ka�dego z nich z dowolnego punktu w formie kierunk�w geograficznych. Partycja obawia si�, �e je�eli rozpocznie poszukiwania osobi�cie, wzbudzi tym czujno�� agent�w. Postanowi�a zatem wykorzysta� do tego celu robota jednak potrzebuje odpowiedniego oprogramowania.

## Wej�cie

Na wej�ciu program otrzymuje trzy liczby naturalne. Pierwsze dwie opisuj� rozmiary mieszkania Partycji w postaci dw�ch liczb **x** oraz **y**. Ostatnia liczba to ilo�� poszukiwanych pluskiew **t**. Do lokalizacji nale�y wykorzysta� funkcj� wbudowan� **std::string test(unsigned &x, unsigned &y, unsigned &id)**. Dwie pierwsze zmienne to wsp�rz�dne robota w pokoju natomiast ostatnia to numer poszukiwanej pluskwy numerowana od 0 do t-1. Funkcja zwraca jeden z o�miu kierunk�w geograficznych (_N_, _NE_, _E_, _SE_, _S_, _SW_, _W_, _NW_) okre�laj�ce w kt�r� stron� nale�y si� poruszy�, �eby znale�� poszukiwany punkt. Je�eli pods�uch znajduje si� w testowanym punkcie, funkcja zwr�ci pusty ci�g znak�w.

## Wyj�cie

Na wyj�ciu program powinien wy�wietli� lokalizacj� wszystkich pluskiew zgodnie z rosn�c� numeracj� id funkcji test.

```
**0 < x ? 2000000000**
<br>
**0 < y ? 2000000000**
<br>
**0 < t ? 100000**
```

### Przyk�adowe wej�cie

```
20 20 2
```

### Przyk�adowe wyj�cie
```
5 5
14 16
```

**Program przesy�any na sprawdzark� _nie mo�e zawiera�_ funkcji test! Zostanie ona automatycznie do��czona przez system do rozwi�zania i jest charakterystyczna dla ka�dego z test�w.**<br>

Funkcja w przyk�adzie jest zdefiniowana nast�puj�co:
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