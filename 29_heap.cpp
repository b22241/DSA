#include <iostream>
#include <vector>
using namespace std;

class Heap {
public:
    vector<int> arr;
    int sie;

    Heap() {
        // Dummy element at index 0
        arr.push_back(-1);
        sie = 0;
    }

    void printHeap() {
        for (int i = 1; i <= sie; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void insert(int val) {
        sie++;
        arr.push_back(val);
        int index = sie;

        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

    void deleteFromHeap() {
        if (sie == 0) {
            cout << "Heap is empty" << endl;
            return;
        }
        arr[1] = arr[sie];   // Move last element to root
        arr.pop_back();
        sie--;

        int index = 1;
        while (true) {
            int left = 2 * index;
            int right = 2 * index + 1;
            int largest = index;

            if (left <= sie && arr[left] > arr[largest]) {
                largest = left;
            }
            if (right <= sie && arr[right] > arr[largest]) {
                largest = right;
            }

            if (largest != index) {
                swap(arr[index], arr[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

    void heapify(int arr[], int n, int i) {
    int largest = i;        // Initialize largest as root
    int left = 2 * i;       // left child
    int right = 2 * i + 1;  // right child

    // If left child is larger than root
    if (left <= n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right <= n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
    
    void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2; i >= 1; i--) {
        heapify(arr, n, i);
    }

    // Extract elements one by one
    for (int i = n; i >= 2; i--) {
        swap(arr[1], arr[i]);   // Move current root to end
        heapify(arr, i - 1, 1); // call heapify on reduced heap
    }
}

};


int main() {
    int arr[100] = {-1, 50, 20, 30, 10, 60, 80, 40}; // -1 at index 0 (dummy for 1-based indexing)
    int n = 7; // number of elements

    cout << "Original array: ";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    Heap h;
    h.heapSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

