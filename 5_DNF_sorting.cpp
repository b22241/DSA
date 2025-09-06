#include <iostream>
#include <algorithm> // For std::swap and std::reverse
#include <map>
#include <set>
#include <vector>
using namespace std;

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//brute force appraoch to sort numbers(colors) in arr
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
//hashmap appraoch  //Time: O(nlogn) Space: O(1)
void sort(int arr[],int n){
    map<int,int>m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    for(auto x:m){
        for(int i=0;i<x.second;i++){
            cout<<x.first<<" ";
        }
    }
}
//multiset appraoch
void sortArray(int arr[], int n) {
    multiset<int> s(arr, arr+n); // O(n log n)
    for (int x : s) cout << x << " ";
}

//Dutch National Flag (DNF) algorithm
//Time: O(n) Space: O(1)
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

//O(n) and O(n) space complexity
void merge_2_sorted_arr(vector<int>& arr1, int n1, vector<int>& arr2, int n2) {
    int i = n1 - n2 - 1;
    int j = n2 - 1;
    int idx = n1 - 1;
    while (i >= 0 && j >= 0) {
        if (arr1[i] < arr2[j]) {
            arr1[idx--] = arr2[j--];
        } else {
            arr1[idx--] = arr1[i--];
        }
    }
    while (i >= 0) {
        arr1[idx--] = arr1[i--];
    }
    while (j >= 0) {
        arr1[idx--] = arr2[j--];
    }
    for(int i=0;i<n1;i++){
        cout<<arr1[i]<<" ";
    }
}

void next_permutation(int arr[], int n) {
    int pivot = -1;

    // find pivot
    for (int i = n - 1; i > 0; i--) {
        if (arr[i - 1] < arr[i]) {   // correct condition
            pivot = i - 1;
            break;
        }
    }

    if (pivot == -1) {
        // if no pivot found, reverse whole array (last permutation)
        reverse(arr, arr + n);
    } else {
        // find element just greater than pivot from right
        for (int i = n - 1; i > pivot; i--) {
            if (arr[i] > arr[pivot]) {
                swap(arr[i], arr[pivot]);
                break;
            }
        }
        // reverse suffix
        reverse(arr + pivot + 1, arr + n);
    }

    // print result
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[]={1,2,3,6,5,4};
    int n=sizeof(arr) / sizeof(arr[0]);
    vector<int>arr1={1,2,3,0,0,0};
    int n1=arr1.size();
    vector<int>arr2={2,5,6};
    int n2=arr2.size();
    // print_array(arr,n);
    // sort(arr,n);
    // merge_2_sorted_arr(arr1,n1,arr2,n2);
    // next_permutation(arr,n);
    int arr3[]={1,2,5,4,3};
    int n3=sizeof(arr3) / sizeof(arr3[0]);
    next(arr3,n3);


}