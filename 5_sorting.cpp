#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

void print_array(vector<int>arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void bubble_sort(vector<int>&arr,int n,int end){
    if (end <= 1) return;
        for(int i=0;i<end-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
        bubble_sort(arr,n,end-1);
}

void selection_sort(vector<int> &arr,int n,int start){
    for(int i=0;i<n-1;i++){
        int smallest_idx=i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[smallest_idx]){
                smallest_idx=j;
            }
        }
        swap(arr[i],arr[smallest_idx]);
    }
}

//sort array with 0,1,2
void sort(vector<int>&arr,int n){
    int xero=0;
    int one=0;
    int two=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            xero++;
        }
        else if(arr[i]==1){
            one++;
        }
        else{
            two++;
        }
    }
    cout<<xero<<" "<<one<<" ";
    cout<<two;
}

//Dutch National Flag(DNF algorithm)
void DNF_sort(vector<int>&arr,int n){
    int mid=0;
    int low=0;
    int high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            mid++;
            low++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[high],arr[mid]);
            high--;
        }
       }
}

//O(n) and O(n) space complexity
void merge_2_sorted_arr(vector<int>& arr1,int n1,vector<int> &arr2,int n2){
   int i=n1-n2-1;
   int j=n2-1;
   int idx=n1-1;
   while(i>=0 && j>=0){
    if(arr1[i]<arr2[j]){
        arr1[idx--]=arr2[j--];
    }
    else{
        arr1[idx--]=arr1[i--];
    }
   }
   while(i>=0){
    arr1[idx--]=arr1[i--];
   }
    while(j>=0){
    arr1[idx--]=arr2[j--];
   }
}

void next_larger(vector<int> &arr,int n){
    int i=0;
    while(arr[i+1]>arr[i]){
        i++;
    }
    int pivot=i-1;
    swap(arr[pivot],arr.back());
    sort(arr.begin()+i,arr.end());
}

int main(){
    // vector<int> arr = {4, 1, 5, 2, 3};
    //int n = arr.size();
    // bubble_sort(arr, n, n);
    // selection_sort(arr, n,0);
    // print_array(arr,n);

    // vector<int> arr = {2,0,2,1,1,0,1,2,0,0};
    // int n = arr.size();
    // //sort(arr,n);
    // DNF_sort(arr,n);
    // print_array(arr,n);

    // vector<int> arr1 = {1,2,3,0,0,0,0};
    // int n1 = arr1.size();
    // vector<int> arr2 = {2,5,6,8};
    // int n2 = arr2.size();
    // merge_2_sorted_arr(arr1,n1,arr2,n2);
    // print_array(arr1,n1);

    // vector<int> arr = {1,2,5,4,3};
    // int n = arr.size();
    // next_larger(arr,n);
    // print_array(arr,n);
}
  