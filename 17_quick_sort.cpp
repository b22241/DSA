#include <bits/stdc++.h>
using namespace std;

//pick the pivot
//partition around pivot
//the elements lesser than pivot are placed on right side of pivot and , larger elements  are placed on right side of pivot

//O(nlogn)->for average time complexity
//O(n2)->for worst case
//O(1)--space complxity
// Quick Sort--choose a pivot point(last element) and place smaller element to left of pivot and larger to right of pivot . After 1 iteration pivot is placed on it's right position. Recursively apply this algo on right and left of pivot         

int partition(vector<int> &arr, int st, int end){
    int idx=st-1;
    int pivot=arr[end];
    for(int j=st;j<end;j++){
        if(arr[j]<=pivot){
            idx++;
            swap(arr[j],arr[idx]);
        }
    }
    idx++;
    swap(arr[end],arr[idx]);
    return idx;
}

void quick_sort(vector<int> &arr,int st, int end){
    if(st<end){
        int piv_idx=partition(arr,st,end);
        quick_sort(arr,st,piv_idx-1); //calls left half of array
        quick_sort(arr,piv_idx+1,end); //calls right half of array
    }
}

int main(){
    vector<int> arr={12,31,35,8,3,17};
    quick_sort(arr,0,arr.size()-1);
    for(int val:arr){
          cout<<val<<" ";
    }
    cout<<endl;
}