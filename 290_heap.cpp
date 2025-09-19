#include <iostream>
using namespace std;

class heap {
public:
    int arr[100];
    int sie = 0;

    void insert(int val) {
        sie++;
        arr[sie] = val;
        int index = sie;
        while (index > 1 && arr[index/2] < arr[index]) {
            swap(arr[index/2], arr[index]);
            index /= 2;
        }
    }

    void heapify(int i, int n) {
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if (left <= n && arr[left] > arr[largest]) largest = left;
        if (right <= n && arr[right] > arr[largest]) largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(largest, n);
        }
    }

    void heapSort() {
        // Build max heap
        for (int i = sie/2; i >= 1; i--) {
            heapify(i, sie);
        }

        int n = sie;
        while (n > 1) {
            swap(arr[1], arr[n]); 
            n--;
            heapify(1, n);       
        }
    }

    void print() {
        for (int i = 1; i <= sie; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// 🔹 Standalone heapify function for raw arrays
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[left] > arr[largest]) largest = left;
    if (right <= n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

int main() {
    // 🔹 Using heap class
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    // cout << "Heap built using class: ";
    // h.print();

    // h.heapSort();
    // cout << "Heap after sorting (class method): ";
    // h.print();

    // 🔹 Using raw array + global heapify
    int arr[6] = {-1, 54, 53, 55, 52, 50}; // 1-based indexing
    int n = 5;

    for (int i = n/2; i > 0; i--) {
        heapify(arr, n, i);
    }

    cout << "Printing the array after building heap: ";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
