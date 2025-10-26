#include <iostream>

using namespace std;

struct Matrix {
    int rows;
    int cols;
    double** data;
};

Matrix* matrix_new(int m, int n) {
    Matrix* mat = new Matrix;
    mat->rows = m;
    mat->cols = n;
    mat->data = new double* [m];
    for (int i = 0; i < m; i++) mat->data[i] = new double[n];
    return mat;
}

void matrix_delete(Matrix* mat) {
    for (int i = 0; i < mat->rows; i++) delete[] mat->data[i];
    delete[] mat->data;
    delete mat;
}

void matrix_input(Matrix* mat) {
    for (int i = 0; i < mat->rows; i++)
        for (int j = 0; j < mat->cols; j++) {
            cout << "Unesi element [" << i << "][" << j << "]: ";
            cin >> mat->data[i][j];
        }
}

void matrix_generate(Matrix* mat, double a, double b) {
    srand(time(nullptr));
    for (int i = 0; i < mat->rows; i++)
        for (int j = 0; j < mat->cols; j++)
            mat->data[i][j] = a + (b - a) * (rand() / (double)RAND_MAX);
}

void matrix_print(Matrix* mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++)
            cout << mat->data[i][j] << " ";
        cout << endl;
    }
}

Matrix* matrix_transpose(Matrix* mat) {
    Matrix* t = matrix_new(mat->cols, mat->rows);
    for (int i = 0; i < mat->rows; i++)
        for (int j = 0; j < mat->cols; j++)
            t->data[j][i] = mat->data[i][j];
    return t;
}

Matrix* matrix_add(Matrix* A, Matrix* B) {
    if (A->rows != B->rows || A->cols != B->cols)
        cout<<"Matrice moraju biti istih dimenzija";
    Matrix* C = matrix_new(A->rows, A->cols);
    for (int i = 0; i < A->rows; i++)
        for (int j = 0; j < A->cols; j++)
            C->data[i][j] = A->data[i][j] + B->data[i][j];
    return C;
}

Matrix* matrix_sub(Matrix* A, Matrix* B) {
    if (A->rows != B->rows || A->cols != B->cols)
        cout << "Matrice moraju biti istih dimenzija";
    Matrix* C = matrix_new(A->rows, A->cols);
    for (int i = 0; i < A->rows; i++)
        for (int j = 0; j < A->cols; j++)
            C->data[i][j] = A->data[i][j] - B->data[i][j];
    return C;
}

Matrix* matrix_mul(Matrix* A, Matrix* B) {
    if (A->cols != B->rows)
        cout << "Matrice moraju biti istih dimenzija";
    Matrix* C = matrix_new(A->rows, B->cols);
    for (int i = 0; i < A->rows; i++)
        for (int j = 0; j < B->cols; j++) {
            C->data[i][j] = 0;
            for (int k = 0; k < A->cols; k++)
                C->data[i][j] += A->data[i][k] * B->data[k][j];
        }
    return C;
}

int main() {
    Matrix* A = matrix_new(2, 3);
    matrix_generate(A, 1.0, 10.0);
    cout << "Matrica A:" << endl;
    matrix_print(A);

    Matrix* B = matrix_new(2, 3);
    matrix_generate(B, 1.0, 10.0);
    cout << "Matrica B:" << endl;
    matrix_print(B);

    Matrix* C = matrix_add(A, B);
    cout << "A + B:" << endl;
    matrix_print(C);

    Matrix* D = matrix_transpose(A);
    cout << "Transponirana matrica A:" << endl;
    matrix_print(D);

    matrix_delete(A);
    matrix_delete(B);
    matrix_delete(C);
    matrix_delete(D);

    return 0;

}
