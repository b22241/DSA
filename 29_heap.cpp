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

    void heapify(int arr[], int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= sie && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right <= sie && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr,largest); 
    }
}


    void sort(){

    }
};

int main() {
    Heap h;
    
    h.insert(70);
    h.insert(60);
    h.insert(55);
    h.insert(55);
    
    h.printHeap();
}
