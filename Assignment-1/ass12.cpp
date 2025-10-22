#include <iostream>
using namespace std;
const int MAX = 100;
void removeDuplicates(int arr[], int &n);
void display(const int arr[], int n);
int main() {
    int arr[MAX], n;
    cout << "Enter number of elements: ";
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];

    removeDuplicates(arr, n);
    cout << "After removing duplicates: ";
    display(arr, n);
    return 0;
}
void removeDuplicates(int arr[], int &n) {
    int write = 0;
    for (int i = 0; i < n; ++i) {
        bool seen = false;
        for (int j = 0; j < write; ++j) {
            if (arr[j] == arr[i]) { seen = true; break; }
        }
        if (!seen) {
            arr[write++] = arr[i];
        }
    }
    n = write;
}
void display(const int arr[], int n) {
    for (int i = 0; i < n; ++i) cout << arr[i] << (i+1<n? " ":"\n");
}
