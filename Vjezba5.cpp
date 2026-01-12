#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<ctime>
using namespace std;

class karta {
public:
    int broj;
    string zog;
};

class mac {
public:
    vector<karta*> karte;

    mac() {
        vector<string> zoge = { "Spade","Bastoni","Denari","Coppe" };
        for (int i = 0; i < 4; i++) {
            for (int b = 1; b <= 10; b++) {
                karta* k = new karta();
                k->broj = b;
                k->zog = zoge[i];
                karte.push_back(k);
            }
        }
    }

    void promijesaj() {
        srand(time(NULL));
        random_shuffle(karte.begin(), karte.end());
    }

    vector<karta*> podijeli() {
        vector<karta*> r;
        for (int i = 0; i < 10; i++) {
            r.push_back(karte.back());
            karte.pop_back();
        }
        return r;
    }
};

class igrac {
public:
    string ime;
    int bodovi;
    vector<karta*> kombinacija;

    igrac(string i) {
        ime = i;
        bodovi = 0;
    }

    void primiKarte(vector<karta*> k) {
        kombinacija = k;
    }

    void izracunajAkuzu() {
        bodovi = 0;

        
        vector<string> zoge = { "Spade","Bastoni","Denari","Coppe" };
        for (string z : zoge) {
            bool ima1 = false, ima2 = false, ima3 = false;
            for (auto c : kombinacija) {
                if (c->zog == z && c->broj == 1) ima1 = true;
                if (c->zog == z && c->broj == 2) ima2 = true;
                if (c->zog == z && c->broj == 3) ima3 = true;
            }
            if (ima1 && ima2 && ima3)
                bodovi += 3;
        }

       
        int count1 = 0, count2 = 0, count3 = 0;
        for (auto c : kombinacija) {
            if (c->broj == 1) count1++;
            if (c->broj == 2) count2++;
            if (c->broj == 3) count3++;
        }

        auto boduj = [&](int x) {
            if (x >= 4) return 4;
            if (x >= 3) return 3;
            return 0;
            };

        bodovi += boduj(count1);
        bodovi += boduj(count2);
        bodovi += boduj(count3);
    }

    void ispisiBodove() {
        cout << ime << " ima " << bodovi << " bodova iz akuže." << endl;
    }
};

int main() {
    int n;
    cout << "Unesi broj igraca: ";
    cin >> n;

    vector<igrac*> igraci;

    for (int i = 0; i < n; i++) {
        string ime;
        cout << "Ime igraca " << i + 1 << ": ";
        cin >> ime;
        igraci.push_back(new igrac(ime));
    }

    mac m;
    m.promijesaj();

    for (auto ig : igraci) {
        ig->primiKarte(m.podijeli());
    }

    cout << "\n--- Bodovi iz zvanja ---\n";
    for (auto ig : igraci) {
        ig->izracunajAkuzu();
        ig->ispisiBodove();
    }

    return 0;
}
