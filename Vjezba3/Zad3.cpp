#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> niz = {1, 2, 3, 4, 5, 6};
    int s = 0;
    int p = 1;
    int prag = 3;

    auto parni = [](int x){ return x % 2 == 0; };
    auto neparni = [](int x){ return x % 2 != 0; };
    auto udvostruci = [](int x){ return x * 2; };
    auto prepolovi = [](int x){ return x / 2; };
    auto dodajUSumu = [&s](int x){ s += x; };
    auto dodajUProdukt = [&p](int x){ p *= x; };
    auto dodajAkoVeciOdPraga = [prag, &s](int x){ if (x > prag) s += x; };

    for (int& x : niz) {
        if (parni(x)) x = prepolovi(x);
        else x = udvostruci(x);
    }

    cout << "Nakon promjene: ";
    for (int x : niz) cout << x << " ";
    cout << "\n";

    for (int x : niz) {
        dodajUSumu(x);
        dodajUProdukt(x);
    }
    cout << "Suma: " << s << ", Produkt: " << p << "\n";

    s = 0;
    for (int x : niz) dodajAkoVeciOdPraga(x);
    cout << "Suma brojeva većih od " << prag << " = " << s << "\n";

  return 0;
}
