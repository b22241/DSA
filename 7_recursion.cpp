#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;


void print_subsets(vector<int>arr,vector<int>ans,int inedx){
    if(inedx == arr.size()){
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }
    // Include the current element
    ans.push_back(arr[inedx]);
    print_subsets(arr, ans, inedx + 1);
    
    // Exclude the current element
    ans.pop_back();
    print_subsets(arr, ans, inedx + 1);
}

//rat in a maze
void helper(vector<vector<int>>&mat,int row, int col, string path,vector<string> &ans,vector<vector<bool>>visited){
    int n=mat.size();
    if(row<0||row>=n||col<0||col>=n ||mat[row][col]==0||visited[row][col]==true){
        return;
    }
    if(row==n-1 && col==n-1){
        ans.push_back(path);
        return;
    }
    visited[row][col]=true;

    helper(mat,row,col+1,path+"R",ans,visited);
    helper(mat,row,col-1,path+"L",ans,visited);
    helper(mat,row-1,col,path+"U",ans,visited);
    helper(mat,row+1,col,path+"D",ans,visited);
    visited[row][col]=true;

}

vector<string>findpath(vector<vector<int>>&mat){
    vector<string>ans;
    string path="";
    int n=mat.size();
    vector<vector<bool>>visited(n,vector<bool>(n,false));
    helper(mat,0,0,path,ans,visited);
    return ans;
}

//merge sort algorithm using recursion
void merge(vector<int>&arr,int st, int mid, int end){
    int i=st;
    int j=mid+1;
    vector<int>temp;
    while(i<=mid && j<=end){
        if(arr[i]>arr[j]){
            temp.push_back(arr[j++]);
        }
        else{
            temp.push_back(arr[i++]);
        }
    }
    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    while(j<=end){
        temp.push_back(arr[j++]);
    }
    for(int idx=0;idx<temp.size();idx++){
        arr[idx+st]=temp[idx];
    }
}

void merge_sort(vector<int>&arr,int st, int end){
    if(st<end){
        int mid=st+(end-st)/2;
        merge_sort(arr,st,mid);
        merge_sort(arr,mid+1,end);
        merge(arr,st,mid,end);
    }
}

//O(n2)
int count_inversion(vector<int>arr){
    int count=0;
    for(int i=0;i<arr.size()-1;i++){
        for(int j=i+1;j<arr.size();j++){
        if(arr[j]<arr[i]){
            count++;
        }
    }
    }
    return count;
}

//O(n)
int count__inversion(vector<int>arr){
    int max=arr[0];
    int count=0;
    for(int i=1;i<arr.size();i++){
        if(arr[i]<max){
            count=count+i;
        }
        else{
            max=arr[i];
        }
    }
    return count;
}

int main() {
    //vector<int> arr = {1, 2, 3};
    //vector<int> ans;
    //print_subsets(arr, ans, 0);

    // vector<vector<int>>mat={{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    // vector<string>ans=findpath(mat);
    // for(string x:ans){
    //     cout<<x<<endl;
    // }

    // vector<int>arr={12,31,35,8,32,17};
    // merge_sort(arr,0,arr.size()-1);
    // for(int x:arr){
    //     cout<<x<<" ";
    //     }

    vector<int>arr={6,3,5,2,7};
    cout<<count__inversion(arr);
    return 0;

}
