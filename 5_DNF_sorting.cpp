#include <iostream>
#include <algorithm> // For std::swap and std::reverse
using namespace std;

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sorting(int arr[],int n){
    int zero=0;
    int one=0;
    int two=0;
    for (int i=0;i<n;i++){
        if(arr[i]==0) zero++;
        if(arr[i]==1) one++;
        if(arr[i]==2) two++;
    }
    int k=0;
    for(int j=0;j<zero;j++){
        arr[k++]=0;
    }
    for(int j=0;j<one;j++){
        arr[k++]=1;
    }
    for(int j=0;j<two;j++){
        arr[k++]=2;
    }
}

void DNF_sorting(int arr[], int n) {
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } 
        if (arr[mid] == 1) {
            mid++; 
        } 
        if(arr[mid] == 2){
            swap(arr[mid], arr[high]);
            high--; 
        }
    }
}

void next_permutation(int arr[], int n) {
    int i = n - 1;
    int pivot;

    // Step 1: Find the pivot where arr[i-1] < arr[i]
    while (i > -1 && arr[i - 1] > arr[i]) {  // STRICTLY '>' (no equal check)
        i--;
    }

    pivot = i - 1;
    cout << "Pivot: " << pivot << endl;

    // If pivot does not exist, reverse the entire array
    if (pivot == 1) {
        reverse(arr, arr + n);
        return;
    }

    else{
         // Step 2: Swap pivot with the last element
    swap(arr[pivot], arr[n - 1]);

    // Step 3: Reverse the suffix correctly
    for (int j = i, k = n - 1; j < k; j++, k--) {
        swap(arr[j], arr[k]);
    }
}
}


int main(){
    int arr[]={1,2,3,6,5,4};
    int n=sizeof(arr) / sizeof(arr[0]);
    next_permutation(arr,n);
    print_array(arr,n);


}