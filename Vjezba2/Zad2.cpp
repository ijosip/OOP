#include <iostream>
using namespace std;

struct vektor {
    int* niz;
    int log;
    int fiz; 
};

vektor* vector_new(int kap) {
    vektor* v = new vektor;
    v->niz = new int[kap];
    v->log = 0;
    v->fiz = kap;
    return v;
}

void vector_delete(vektor* v) {
    delete[] v->niz;
    delete v;
}

void vector_push_back(vektor* v, int x) {
    if (v->log >= v->fiz) {
        int* new_array = new int[v->fiz * 2];
        for (int i = 0; i < v->log; i++) new_array[i] = v->niz[i];
        delete[] v->niz;
        v->niz = new_array;
        v->fiz *= 2;
    }
    v->niz[v->log++] = x;
}

void vector_pop_back(vektor* v) {
    if (v->log > 0) {
        v->log--;
        v->niz[v->log] = 0;
    }
}

int vector_front(vektor* v) {
    if (v->log == 0) cout<<"Vektor je prazan";
    return v->niz[0];
}

int vector_back(vektor* v) {
    if (v->log == 0) cout << "Vektor je prazan";
    return v->niz[v->log - 1];
}

int vector_size(vektor* v) {
    return v->log;
}

int main(void) {

    vektor* v = vector_new(2);

    vector_push_back(v, 5);
    vector_push_back(v, 10);
    vector_push_back(v, 15);
    cout << "Elementi vektora: ";

    for (int i = 0; i < vector_size(v); i++) cout << v->niz[i] << " ";
    cout << endl;


    cout << "Prvi: " << vector_front(v) << ", Zadnji: " << vector_back(v) << endl;

    vector_pop_back(v);

    cout << "Nakon funkcije log: " << vector_size(v) << endl;

    vector_delete(v);

    return 0;
}
