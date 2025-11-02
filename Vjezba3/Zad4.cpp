#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Student {
    string ime;
    string jmbag;
    int godina;
    int ects;
    double prosjek;
};

void filter_students(vector<Student>& v,
                     void (*akcija)(Student&),
                     bool (*filter)(Student&)) {
    for (auto& s : v)
        if (filter(s))
            akcija(s);
}

void ispisi(Student& s) {
    cout << s.ime << " (" << s.godina << " god, " << s.ects << " ECTS, prosjek " << s.prosjek << ")\n";
}

void povecajGodinu(Student& s) {
    s.godina++;
}

int main() {
    vector<Student> studenti = {
        {"Ivan", "001", 1, 30, 3.7},
        {"Ana", "002", 1, 0, 2.8},
        {"Marko", "003", 2, 45, 4.0},
        {"Lana", "004", 3, 55, 3.9}
    };

    cout << "Prva godina, položili barem 1:\n";
    filter_students(studenti, ispisi, [](Student& s){ return s.godina == 1 && s.ects > 0; });

    cout << "\nProsjek > 3.5:\n";
    filter_students(studenti, ispisi, [](Student& s){ return s.prosjek > 3.5; });

    filter_students(studenti, povecajGodinu, [](Student& s){ return s.ects >= 45; });

    cout << "\nNakon povećanja godine:\n";
    for (auto& s : studenti) ispisi(s);

  return 0;
}
