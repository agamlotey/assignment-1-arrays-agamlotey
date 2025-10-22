#include <iostream>
using namespace std;
const int MAX = 50;
void reverseArray(int arr[], int n);
void printArray(const int arr[], int n);
void transposeMatrix(int A[][MAX], int T[][MAX], int r, int c);
void multiplyMatrices(int A[][MAX], int B[][MAX], int C[][MAX], int r1, int c1, int r2, int c2);
void printMatrix(int M[][MAX], int r, int c);

int main() {
    int arr[] = {1,2,3,4,5};
    int n = 5;
    cout << "Original array: ";
    printArray(arr, n);
    reverseArray(arr, n);
    cout << "Reversed array: ";
    printArray(arr, n);
    int A[MAX][MAX] = { {1,2,3}, {4,5,6} };
    int r = 2, c = 3;
    int T[MAX][MAX] = {0};
    transposeMatrix(A, T, r, c);
    cout << "Original matrix:\n"; printMatrix(A, r, c);
    cout << "Transpose:\n"; printMatrix(T, c, r);
    int B[MAX][MAX] = { {7,8}, {9,10}, {11,12} };
    int C[MAX][MAX] = {0};
    multiplyMatrices(A, B, C, 2, 3, 3, 2); 
    cout << "Product A * B:\n"; printMatrix(C, 2, 2);
    return 0;
}
void reverseArray(int arr[], int n) {
    int i = 0, j = n - 1;
    while (i < j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
        ++i; --j;
    }
}
void printArray(const int arr[], int n) {
    for (int i = 0; i < n; ++i) cout << arr[i] << (i+1<n? " ":"\n");
}
void transposeMatrix(int A[][MAX], int T[][MAX], int r, int c) {
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            T[j][i] = A[i][j];
}
void multiplyMatrices(int A[][MAX], int B[][MAX], int C[][MAX], int r1, int c1, int r2, int c2) {
    if (c1 != r2) {
        cout << "Incompatible sizes for multiplication\n";
        return;
    }
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < c1; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
void printMatrix(int M[][MAX], int r, int c) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) cout << M[i][j] << " ";
        cout << "\n";
    }
}
