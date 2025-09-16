#include <bits/stdc++.h>
using namespace std;


//O(n2)
int count(vector<int>arr){
    int n=arr.size();
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                count++;
            }
        }
    }
    return count;
}

//optimised appraoch
int merge(vector<int> &arr, int st, int mid, int end) {
    vector<int> temp;
    int i = st, j = mid + 1;
    int inversionCount=0;
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
            inversionCount=inversionCount+(mid-i+1);
        }
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= end) temp.push_back(arr[j++]);

    for (int idx = 0; idx < temp.size(); idx++) {
        arr[idx + st] = temp[idx];
    }
    return inversionCount;
}

int mergeSort(vector<int> &arr, int st, int end) {
    if (st >= end) return 0;   // ✅ Fix: base case

    int mid = st + (end - st) / 2;
    int leftCount=mergeSort(arr, st, mid);
    int rightCount=mergeSort(arr, mid + 1, end);
    int inversionCount=merge(arr, st, mid, end);
    return leftCount+rightCount+inversionCount;

}

    

int main(){
    vector<int>arr={6,3,5,2,7};
    // cout<<count(arr);
    cout<<mergeSort(arr,0,arr.size()-1);
}