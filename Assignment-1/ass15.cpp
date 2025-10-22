#include <iostream>
using namespace std;
const int MAX = 50;
void sumRowsAndCols(int M[][MAX], int r, int c);
int main() {
    int M[MAX][MAX];
    int r, c;
    cout << "Enter rows and cols: ";
    cin >> r >> c;
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            cin >> M[i][j];

    sumRowsAndCols(M, r, c);
    return 0;
}
void sumRowsAndCols(int M[][MAX], int r, int c) {
    for (int i = 0; i < r; ++i) {
        int sumRow = 0;
        for (int j = 0; j < c; ++j) sumRow += M[i][j];
        cout << "Sum of row " << i << " = " << sumRow << "\n";
    }
    for (int j = 0; j < c; ++j) {
        int sumCol = 0;
        for (int i = 0; i < r; ++i) sumCol += M[i][j];
        cout << "Sum of column " << j << " = " << sumCol << "\n";
    }
}
