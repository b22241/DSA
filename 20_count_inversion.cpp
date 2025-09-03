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

//optimisied approach
//O(nlogn)->for average time complexity
int merge(vector<int> &arr, int st,int mid, int end){
    vector<int>temp;
    int  i=st;
    int j=mid+1;
    int invcount=0;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
            invcount=invcount+(mid-i+1);
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }
    for(int idx=0;idx<temp.size();idx++){
        arr[idx+st]=temp[idx];
    }
    return invcount;
}

int merge_sort(vector<int> &arr, int st, int end){
    if(st<end){
        int mid=st+(end-st)/2;
        int leftcount=merge_sort(arr,st,mid);
        int rightcount=merge_sort(arr,mid+1,end);
        int invcount=merge(arr, st, mid,end);
        return leftcount+rightcount+invcount;
    }
    return 0; // Return 0 when st >= end
}
int main(){
    vector<int>arr={1,3,5,10,2,6,7,8};
    // cout<<count(arr);
    int ans=merge_sort(arr,0,arr.size()-1);
    cout<<ans;
    return 0;

}