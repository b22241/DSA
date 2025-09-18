#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// // O(n) spce- O(n)
// int rainwater(vector<int> v) {
//     vector<int> right_max;
//     vector<int> left_max;

//     left_max.push_back(v[0]);
//     for (int i = 1; i < v.size(); i++) {
//         if (v[i] > left_max[i - 1]) {
//             left_max.push_back(v[i]);
//         } else {
//             left_max.push_back(left_max[i - 1]);
//         }
//     }

//     right_max.push_back(v[v.size() - 1]);
//     for (int i = v.size() - 2; i >= 0; i--) {
//         if (v[i] > right_max.back()) {
//             right_max.push_back(v[i]);
//         } else {
//             right_max.push_back(right_max.back());
//         }
//     }
//    reverse(right_max.begin(), right_max.end());  // Fix: reverse to match original indices

//     int rainwater = 0;
//     for (int i = 0; i < v.size(); i++) {
//         rainwater += min(left_max[i], right_max[i]) - v[i];
//     }

//     return rainwater;
// }

//time -O(n) space-O(1); more optimised appraoch
// int trap(vector<int>& height) {
//     int n=height.size();
//     int l=0;
//     int r=n-1;
//     int left_max=height[0];
//     int right_max=height[n-1];
//     int area=0;
//     while(l<=r){
//         left_max=max(height[l],left_max);
//         right_max=max(height[r],right_max);
//         if(left_max>right_max){
//             area=area+right_max-height[r];
//             r--;
//         }
//         else{
//             area=area+left_max-height[l];
//             l++;
//         }
//     }
//     return area;  
// }

// int main() {
//     vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
//     cout << rainwater(v);
// }

//find the celebrity
int celebrity(vector<vector<int>>arr){
    int n=arr.size();
    int ans=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==1){
                break;
            }
        }
    }
    return ans;
}


int main(){
    vector<vector<int>>arr={{0,1,0},{0,0,0},{0,1,0}};
    cout<<celebrity(arr);
}
// vector<int>sliding_window(vector<int>window,int k){
//     int n =window.size();
//     vector<int>output;
//     int i=0;
//     int val_max=max({window[i],window[i+1],window[i+1]});
//     output.push_back(val_max);

//     for(int j=k;j<n-2;j++){
//         val_max=max(window[j],val_max);
//         output.push_back(val_max);
//     }
// }

// int main(){
//     vector<int>window={1,3,-1,-3,5,3,6,7};
//     int k=3;
//     vector<int> ans=sliding_window(window, k);
//     for (int x:ans){
//         cout<<x<<" ";
//     }
//     return 0;
// }