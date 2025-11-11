#include <bits/stdc++.h>
using namespace std;

class heap {
public:
    int arr[100];
    int sie = 0;

//insert element in heap
void insert(int val) {
    sie++;
    arr[sie] = val;
    int index = sie;
    while (index > 1) {
        int parent=index/2;
        if(arr[index]>arr[parent]){
            swap(arr[parent], arr[index]);
            index=parent;
        }
        else{
            return;
        }
    }
}

//delete root from heap
void deleteFromHeap(){
    if(sie==0){
        cout<<"can't delete anythign";
        return;
    }

    arr[1]=arr[sie];
    sie--;

    int i=1;
    while(i<sie){
        int leftIndex=2*i;
        int rightIndex=2*i+1;

        if(leftIndex<sie && arr[leftIndex]>arr[i]){
            swap(arr[i],arr[leftIndex]);
            i=leftIndex;
        }
        else if(rightIndex<sie && arr[rightIndex]>arr[i]){
            swap(arr[i],arr[rightIndex]);
            i=rightIndex;
        }
        else{
            return;
        }
    }
}

void print() {
    for (int i = 1; i <= sie; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
};

//ek element to shi jgh phucha do
void heapify(vector<int>&arr,int i, int n) {
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if (left <= n && arr[left] > arr[largest]) largest = left;
        if (right <= n && arr[right] > arr[largest]) largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr,largest, n);
        }
}

//a arrary is given,print elements of arr in sorted order by heapsort algo
void heapSort(vector<int>&arr,int n) {
    // Build max heap
    int a=n;
    while(a>1){
        swap(arr[1],arr[a]);
        a--;
        heapify(arr,1,a);
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
    h.insert(542);
    // h.deleteFromHeap();
    // cout << "Heap built using class: ";
    // h.print();

    // h.heapSort();
    // cout << "Heap after sorting (class method): ";
    // h.print();

    // 🔹 Using raw array + global heapify
    vector<int>arr = {-1, 54, 53, 55, 52, 50}; // 1-based indexing
    int n = 5;

    for (int i = n/2; i > 0; i--) {
        heapify(arr, i, n);
    }

    // cout << "Printing the array after building heap: ";
    // for (int i = 1; i <= n; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    heapSort(arr,n);
    for(int val:arr){
        cout<<val<<" ";
    }


}
