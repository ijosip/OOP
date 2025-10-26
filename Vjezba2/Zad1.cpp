#include <iostream>

using namespace std;

int* fun(int n) {
	int* niz = new int[n];
	niz[0] = 0;
	niz[1] = niz[2] = 1;
	for (int i = 2;i < n;i++) {
		niz[i] = niz[i - 1] + niz[i - 2];
	}
	return niz;
}

int main(void) {
	int n;
	cout << "Unesi broj n" << endl;
	cin >> n;

	int* niz = fun(n);
	for (int i = 0;i < n;i++)
		cout << niz[i]<< "\t";

	delete niz;
	niz = nullptr;

	return 0;
}
