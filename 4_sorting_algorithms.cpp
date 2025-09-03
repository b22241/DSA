#include <iostream>
using namespace std;


void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubble_sort(int arr[],int n){ //O(n*2)
    for (int i=0;i<n-1;i++){
        bool isSwap=false;
        for (int j=0;j<n-i-1;j++){
            if (arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                isSwap=true;
            }
           
        }
        if(!isSwap){//alrady sorted
            return;
        }
    }
}

void selection_sort(int arr[], int n) {  //O(n*2)
    for (int i = 0; i < n - 1; i++) {  // Runs till n-1, last element is automatically sorted
        int smallest_index = i;

        for (int j = i + 1; j < n; j++) { // Should start from i+1, not i
            if (arr[j] < arr[smallest_index]) { // Compare with arr[j], not arr[i]
                smallest_index = j;
            }
        }

        swap(arr[smallest_index], arr[i]); // Swap smallest element with the first element of the unsorted part
    }
}

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {  
        int current = arr[i];  // Store current value
        int previous = i - 1;  

        // Move elements greater than current to one position ahead
        while (previous >= 0 && arr[previous] > current) {
            arr[previous + 1] = arr[previous];
            previous--;
        }

        // Place current at the correct position
        arr[previous + 1] = current;
    }
}

int main() {
    int arr[] = {64, 25, 12, 22,-1};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertion_sort(arr, n);
    print_array(arr, n);

    return 0;
}
