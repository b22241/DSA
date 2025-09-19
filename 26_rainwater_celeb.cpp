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
// int celebrity(vector<vector<int>> arr) {             //O(n2)
//     int n = arr.size();    
    
//     for(int i=0; i<n; i++) {
//         bool rowAllZero = true;
//         for(int j=0; j<n; j++) {
//             if(arr[i][j] == 1) {   // person i knows someone
//                 rowAllZero = false;
//                 break;
//             }
//         }
//         if(!rowAllZero) continue; // not a celeb, go next row

//         bool colAllOne = true;
//         for(int k=0; k<n; k++) {
//             if(i == k) continue;
//             if(arr[k][i] == 0) {   // someone doesn’t know i
//                 colAllOne = false;
//                 break;
//             }
//         }

//         if(colAllOne) return i; // found celebrity
//     }

//     return -1; // no celebrity
// }

// int celeb(vector<vector<int>> arr) {         //O(n)
//     int n = arr.size();
//     stack<int> s;
//     for(int i=0; i<n; i++){
//         s.push(i);
//     }
//     while(s.size() > 1){
//         int a = s.top(); s.pop();
//         int b = s.top(); s.pop();

//         if(arr[a][b] == 1){
//             s.push(b);
//         } else {
//             s.push(a);
//         }
//     }
//     int cand = s.top();
//     for(int i=0; i<n; i++){
//         if(i != cand){
//             if(arr[cand][i] == 1) return -1; 
//             if(arr[i][cand] == 0) return -1; 
//         }
//     }
//     return cand;
// }



// int main(){
// vector<vector<int>> arr = {
//     {0, 0, 0, 1},  // person 0 knows 3
//     {0, 0, 0, 1},  // person 1 knows 3
//     {0, 0, 0, 1},  // person 2 knows 3
//     {0, 0, 0, 0}   // person 3 knows nobody
// };
// cout<<celeb(arr);
// }



