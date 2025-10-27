#include <iostream>
using namespace std;

struct Student {
	 int godina_studija;
	 char* ime;
};

void ispis(Student* s, int godina) {
	for (int i = 0; i < 5; i++) {
		if (s[i].godina_studija > godina) cout << "Student je " << s[i].godina_studija << " godina studija" << endl;
	}
}

int main(void) {
	Student niz[5];
	niz[0].godina_studija = 1; 
	niz[1].godina_studija = 2;
	niz[2].godina_studija = 3;
	niz[3].godina_studija = 4;
	niz[4].godina_studija = 5;


	int godina = 3;
	ispis(niz,godina);

	return 0;
}
