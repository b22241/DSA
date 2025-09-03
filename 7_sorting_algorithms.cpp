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

void insertion_sort(int arr[], int n) {//O(n*2)
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

//Method 1
void merge_2_sorted_arrays1(int arr1[], int n1, int arr2[], int n2, int merged[]) {
    int i = 0, j = 0, k = 0;

    // Merge both arrays into merged[]
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            merged[k] = arr1[i];
            k++;
            i++;
        } else {
            merged[k] = arr2[j];
            j++;
            k++;
        }
    }

    // Copy remaining elements of arr1 (if any)
    while (i < n1) {
        merged[k] = arr1[i];
        k++;
        i++;
    }

    // Copy remaining elements of arr2 (if any)
    while (j < n2) {
        merged[k] = arr2[j];
        k++;
        j++;
    }
}

//Method 2
void merge_2_sorted_arrays2(int arr1[],int m,int arr2[],int n){
    int idx=m+n-1;
    int i=m-1;
    int j=n-1;
    while(j>=0){
        if(arr1[i]<arr2[j]){
            arr1[idx]=arr2[j];
            j--;
            idx--;
        }
        if(arr1[i]>arr2[j]){
            arr1[idx]=arr1[i];
            i--;
            idx--;
        }
    }
    while(j>=0){
        arr1[idx]=arr2[j]
        idx--;
        j--;
    }
}

int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);


    merge_2_sorted_arrays2(arr1,m,arr2,n);
    print_array(merged,n1+n2);

    return 0;
}
