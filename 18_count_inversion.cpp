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


int main(){
    vector<int>arr={6,3,5,2,7};
    cout<<count(arr);
}