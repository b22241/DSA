#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//push largest element in the end
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

//assume 2 arrays, leftone is sorted and right one is unsorted, now pick the smallest elemtnt form right(unsorted arr) and place it in sorted arr.repet this till last element
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

//Start with the first element → already sorted (since a single element is trivially sorted).Take the next element and insert it into the correct position in the sorted part.Keep repeating: pick one element at a time and insert it into its proper place among the already sorted elements.At the end, the whole array becomes sorted.
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
    // bubble_sort(arr,n);
    // selection_sort(arr,n);
    // insertion_sort(arr, n);

    print_array(arr, n);
}
