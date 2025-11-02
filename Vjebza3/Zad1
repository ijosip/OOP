#include <iostream>
#include <cstddef> 
using namespace std;

inline bool ascending(int a, int b) {
    return a > b;
}

inline bool descending(int a, int b) {
    return a < b;
}

void sortt(int arr[],size_t n, bool (*cmp)(int, int)) {
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (cmp(arr[j], arr[j + 1])) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = { 5, 2, 9, 1, 7 };
   size_t n = sizeof(arr) / sizeof(arr[0]);

    cout << "Uzlazno: ";
    sortt(arr, n, ascending);
    for (size_t i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";

    cout << "Silazno: ";
    sortt(arr, n, descending);
    for (size_t i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
