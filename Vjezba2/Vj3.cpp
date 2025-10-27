#include<iostream>
#include <cstddef>
using namespace std;


void sortt(int[], std::size_t, bool(*cmp)(int, int));

inline bool ascending(int a, int b) {
	return  a > b;
}

inline bool descending(int a, int b) {
	return  a < b;
}

int main(void) {
	int niz[5] = {11,2,30,4,15};
	sortt(niz,5,ascending);
	sortt(niz, 5, descending);
	return 0;

}

void sortt(int niz[], std::size_t n, bool(*cmp)(int a, int b)) {
	cmp = ascending;
	for (int i = 1; i < n; i++) {
		cmp(niz[i - 1], niz[i]);
	}
}


