#include <iostream>
#include <cstddef>
using namespace std;

template <typename T>
inline bool ascending(T a, T b) {
    return a > b;
}

template <typename T>
inline bool descending(T a, T b) {
    return a < b;
}

template <typename T>
void sortt(T arr[], size_t n, bool (*cmp)(T, T)) {
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (cmp(arr[j], arr[j + 1])) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int a[] = { 5, 2, 9, 1, 7 };
    double b[] = { 3.1, 2.4, 9.9, 1.2 };

    size_t n1 = sizeof(a) / sizeof(a[0]);
    size_t n2 = sizeof(b) / sizeof(b[0]);

    cout << "Int uzlazno: ";
    sortt(a, n1, ascending<int>);
    for (auto x : a) cout << x << " ";
    cout << "\n";

    cout << "Double silazno: ";
    sortt(b, n2, descending<double>);
    for (auto x : b) cout << x << " ";
    cout << "\n";
}
