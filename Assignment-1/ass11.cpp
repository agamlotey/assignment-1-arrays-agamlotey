#include <iostream>
using namespace std;
const int MAX = 100;
void createArray(int arr[], int &n);
void displayArray(const int arr[], int n);
void insertElement(int arr[], int &n);
void deleteElement(int arr[], int &n);
void linearSearch(const int arr[], int n);
int main() {
    int arr[MAX];
    int n = 0;
    int choice;
    do {
        cout << "\n—— MENU ——\n";
        cout << "1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR SEARCH\n6. EXIT\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createArray(arr, n); break;
            case 2: displayArray(arr, n); break;
            case 3: insertElement(arr, n); break;
            case 4: deleteElement(arr, n); break;
            case 5: linearSearch(arr, n); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);
    return 0;
}
void createArray(int arr[], int &n) {
    cout << "Enter number of elements (max " << MAX << "): ";
    cin >> n;
    if (n < 0) n = 0;
    if (n > MAX) {
        cout << "Too many elements. Limiting to " << MAX << ".\n";
        n = MAX;
    }
    for (int i = 0; i < n; ++i) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }
}
void displayArray(const int arr[], int n) {
    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << (i+1 < n ? " " : "\n");
    }
}
void insertElement(int arr[], int &n) {
    if (n >= MAX) {
        cout << "Array full. Cannot insert.\n";
        return;
    }
    int pos, val;
    cout << "Enter position to insert (0 to " << n << "): ";
    cin >> pos;
    if (pos < 0 || pos > n) {
        cout << "Invalid position.\n";
        return;
    }
    cout << "Enter value to insert: ";
    cin >> val;
    for (int i = n; i > pos; --i) arr[i] = arr[i-1];
    arr[pos] = val;
    ++n;
    cout << "Inserted.\n";
}
void deleteElement(int arr[], int &n) {
    if (n == 0) {
        cout << "Array is empty. Nothing to delete.\n";
        return;
    }
    int pos;
    cout << "Enter position to delete (0 to " << n-1 << "): ";
    cin >> pos;
    if (pos < 0 || pos >= n) {
        cout << "Invalid position.\n";
        return;
    }
    for (int i = pos; i < n-1; ++i) arr[i] = arr[i+1];
    --n;
    cout << "Deleted element at position " << pos << ".\n";
}
void linearSearch(const int arr[], int n) {
    if (n == 0) {
        cout << "Array empty.\n";
        return;
    }
    int key;
    cout << "Enter value to search: ";
    cin >> key;
    bool found = false;
    cout << "Found at index(es): ";
    for (int i = 0; i < n; ++i) {
        if (arr[i] == key) {
            cout << i << " ";
            found = true;
        }
    }
    if (!found) cout << "None";
    cout << "\n";
}
