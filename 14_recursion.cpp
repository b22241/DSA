#include <cmath>
#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <numeric>             //to find sum of elements in vector
using namespace std;

//check if arr is sorted
// bool isSorted(vector<int>vec,int index){   
//     int n=vec.size();
//     if(index==n-1) return true;
//     return isSorted(vec,index+1) && vec[index+1]>=vec[index];
//     return false;
// }

// print all subsets of an array
// void printSubsets(vector<int> &arr, vector<int> &ans, int i) {              // //O(2^n*n)
//     // Base case: when i reaches the end of arr
//     if (i == arr.size()) {
//         for (int val : ans) {
//             cout << val << " ";
//         }
//         cout << endl;
//         return;
//     }
//     // Include the current element in subset
//     ans.push_back(arr[i]);
//     printSubsets(arr, ans, i + 1);
//     // Exclude the current element from subset (backtracking)
//     ans.pop_back();
//     printSubsets(arr, ans, i + 1);
// }

// //if values are repeating in arr,we can store values in set , set stores uniwure values
// //method 1
// // void printSubsets(vector<int> &arr, set<vector<int>> &ans, int i,vector<int>&subset) {              // //O(2^n*n)
// //     // Base case: when i reaches the end of arr
// //     if (i == arr.size()) {
// //         ans.insert(subset);
// //         return;
// //     }
// //     // Include the current element in subset
// //     subset.push_back(arr[i]);
// //     printSubsets(arr, ans, i + 1,subset);
// //     // Exclude the current element from subset (backtracking)
// //     subset.pop_back();
// //     printSubsets(arr, ans, i + 1,subset);
// // }

// // //method 2 for this
// // void printSubsets_(vector<int> &arr, vector<vector<int>> &ans, int i,vector<int>&subset) {              // //O(2^n*n)
// //     // Base case: when i reaches the end of arr
// //     if (i == arr.size()) {
// //         ans.push_back(subset);
// //         return;
// //     }
// //     // Include the current element in subset
// //     subset.push_back(arr[i]);
// //     printSubsets_(arr, ans, i + 1, subset);
// //     // Exclude the current element from subset (backtracking)
// //     subset.pop_back();
// //     int idx = i + 1;
// //     while (idx < arr.size() && arr[idx] == arr[idx - 1]) idx++;
// //     printSubsets_(arr, ans, idx, subset);
// // }


// int main() {
//     vector<int> arr = {1, 2, 3}; // Input set
//     vector<int> ans; // To store subsets
//     vector<int>subset;
//     // cout<<isSorted(arr,0);
//     printSubsets(arr, ans, 0);
//     for(int x:ans){
//         cout<<x;
//     }
// }



// class Solution {
// public:
//     set<vector<int>> s;

//     void allcombination(vector<int>& arr, int idx, int target, vector<int>& combination, vector<vector<int>>& ans) {
//         if (idx == arr.size() || target < 0) {
//             return;
//         }

//         if (target == 0) {
//             if (s.find(combination) == s.end()) { // Fixed missing parenthesis
//                 ans.push_back(combination); // Fixed incorrect insertion
//                 s.insert(combination);
//             }
//             return;
//         }

//         // Include the current element (single occurrence)
//         combination.push_back(arr[idx]);
//         allcombination(arr, idx + 1, target - arr[idx], combination, ans);

//         // Include the current element (multiple occurrences)
//         allcombination(arr, idx, target - arr[idx], combination, ans);

//         // Exclude the current element (backtracking)
//         combination.pop_back();
//         allcombination(arr, idx + 1, target, combination, ans);
//     }

//     vector<vector<int>> combinationSum(vector<int>& arr, int target) {
//         vector<vector<int>> ans;
//         vector<int> combination;
//         allcombination(arr, 0, target, combination, ans);
//         return ans;
//     }
// };

// int main() {
//     Solution sol;
//     vector<int> arr = {2, 3, 6, 7};
//     int target = 7;

//     vector<vector<int>> result = sol.combinationSum(arr, target);

//     // Print the result
//     for (auto vec : result) {
//         cout << "[ ";
//         for (int num : vec) {
//             cout << num << " ";
//         }
//         cout << "]\n";
//     }

//     return 0;
// }


///sudoku solver problem
// class Solution {
// public:
//     bool helper(vector<vector<char>>& board, int row, int col) {
//         if (row == 9) return true;

//         int next_row = row;
//         int next_col = col + 1;
//         if (next_col == 9) {
//             next_row = row + 1;
//             next_col = 0;
//         }
//         if (board[row][col] != '.') {
//             return helper(board, next_row, next_col);
//         }

//         for (char digit = '1'; digit <= '9'; digit++) {
//             if (isSafe(board, digit, row, col)) {
//                 board[row][col] = digit;
//                 if (helper(board, next_row, next_col)) return true; ///backtracking
//                 board[row][col] = '.';
//             }
//         }

//         return false;
//     }

//     bool isSafe(vector<vector<char>>& board, char digit, int row, int col) {
//         for (int j = 0; j < 9; j++) {
//             if (board[row][j] == digit) return false;
//         }
//         for (int i = 0; i < 9; i++) {
//             if (board[i][col] == digit) return false;
//         }

//         int start_row = row - row % 3;
//         int start_col = col - col % 3;
//         for (int i = start_row; i < start_row + 3; i++) {
//             for (int j = start_col; j < start_col + 3; j++) {
//                 if (board[i][j] == digit) return false;
//             }
//         }

//         return true;
//     }

//     void solveSudoku(vector<vector<char>>& board) {
//         helper(board, 0, 0);
//     }
// };

//rat in a maze problem
// void rat(vector<vector<int>> &maze, int row, int col, vector<char> &path, vector<vector<char>> &ans) {
//     int n = maze.size();

//     // boundary check
//     if (row < 0 || col < 0 || row >= n || col >= n || maze[row][col] == 0) return;

//     // reached destination
//     if (row == n - 1 && col == n - 1) {
//         ans.push_back(path);
//         return;
//     }

//     // mark visited
//     maze[row][col] = 0;

//     // Move Down
//     path.push_back('D');
//     rat(maze, row + 1, col, path, ans);
//     path.pop_back();

//     // Move Right
//     path.push_back('R');
//     rat(maze, row, col + 1, path, ans);
//     path.pop_back();

//     // unmark visited (backtrack)
//     maze[row][col] = 1;
// }

// int main() {
//     vector<vector<int>> maze = {
//         {1, 0, 0, 0},
//         {1, 1, 0, 1},
//         {1, 1, 0, 0},
//         {0, 1, 1, 1}
//     };

//     vector<char> path;
//     vector<vector<char>> ans;
//     rat(maze, 0, 0, path, ans);

//     // print all paths
//     for (auto p : ans) {
//         for (char step : p) {
//             cout << step;
//         }
//         cout << " ";
//     }
//     cout << endl;
// }


//combination sum probelm
//this can be furtehr optimied .insted of computing sum of ans array again and again, we can minun arr[i] from target and check if it's equal to 0 or not;
// void sum(vector<int> arr, int i, int target, vector<int>& ans, vector<vector<int>>& finalAnswer) {
//     if (accumulate(ans.begin(), ans.end(), 0) == target) {
//         finalAnswer.push_back(ans);
//         return;
//     }
//     if (accumulate(ans.begin(), ans.end(), 0) > target) {
//         return;
//     }
//     if (i == arr.size()) return;  

//     // take arr[i]
//     ans.push_back(arr[i]);
//     sum(arr, i, target, ans, finalAnswer);  // stay at i
//     ans.pop_back();

//     // skip arr[i]
//     sum(arr, i + 1, target, ans, finalAnswer);
// }

// int main() {
//     vector<int> arr = {2, 3, 5};
//     int target = 8;
//     vector<int> ans;
//     vector<vector<int>> finalAnswer;
//     sum(arr, 0, target, ans, finalAnswer);

//     for (auto& p : finalAnswer) {
//         for (int x : p) {
//             cout << x << " ";
//         }
//         cout << endl;
//     }
// }

//Palindrome Partitioning Problem
// bool isPalindrome(vector<char>ans){
//     int n=ans.size();
//     if(n==1){
//         return true;
//     }
//     for(int i=0;i<n/2;i++){
//         if(ans[i]!=ans[n-i-1]){
//             return false;
//             break;
//         }
//     }
//     return true;
// }
// void printSubsets(string s,int i, vector<char> &ans, vector<vector<char>>&finalAnswer) {              // //O(2^n*n)
//     // Base case: when i reaches the end of arr
//     if (i == s.length()) {
//         if(isPalindrome(ans)){
//             finalAnswer.push_back(ans);
//             return;
//         }
//         return;
//     }
//     // Include the current element in subset
//     ans.push_back(s[i]);
//     printSubsets(s, i+1,ans,finalAnswer);
//     // Exclude the current element from subset (backtracking)
//     ans.pop_back();
//     printSubsets(s, i+1,ans,finalAnswer);
// }

// int main(){
//     string s="aab";
//     vector<char>ans;
//     vector<vector<char>>finalAnswer;
//     printSubsets(s,0,ans,finalAnswer);
//     for(auto x:finalAnswer){
//         for(char c:x){
//             cout<<c;
//         }
//         cout<<" ";
//     }
// }


//MERGE SORT- divide till last and merge them in sorted order
// void merge(vector<int>&arr,int start,int mid,int end){        //O(n)   
//     vector<int>ans;
//     int i=start;
//     int j=mid+1;
//     while(i<=mid && j<=end){
//         if(arr[i]>arr[j]){
//             ans.push_back(arr[j]);
//             j++;
//         }
//         else{
//             ans.push_back(arr[i]);
//             i++;
//         }
//     }
//     while(i<=mid){
//         ans.push_back(arr[i++]);
//     }
//     while(j<=end){
//         ans.push_back(arr[j++]);
//     }
//     for(int idx=0;idx<ans.size();idx++){
//         arr[idx+start]=ans[idx];
//     }
// }


// //merge sort      O(nlogn)  space complexity-O(n), but quicsort has O(1) space complexity, though quick sort has time complxity O(n2) in worst case
// void mergeSort(vector<int>&arr,int start,int end){             //O(logn)
//     if(start<end){
//         int mid=start+(end-start)/2;
//         mergeSort(arr,start,mid);
//         mergeSort(arr,mid+1,end);
//         merge(arr,start,mid,end);
//     }
// }

// int main(){
//     vector<int>arr={12,31,35,32,17};
//     mergeSort(arr,0,arr.size()-1);
//         for(int x:arr){
//         cout<<x<<" ";
//     }
// }


//Quick Sort--choose a pivot point(last element) and place smaller element to left of pivot and larger to right of pivot . After 1 iteration pivot is placed on it's right position. Recursively apply this algo on right and left of pivot
// int partition(vector<int>&arr,int start,int end){            
//     int pivot=end;
//     int idx=start-1;
//     for(int i=start;i<end;i++){
//         if(arr[i]<=arr[pivot]){
//             idx++;
//             swap(arr[i],arr[idx]);
//         }
//     }
//     idx++;
//     swap(arr[end],arr[idx]);
//     return idx;
// }

// void quickSort(vector<int>&arr,int start,int end){              //O(nlogn)
//     if(start<end){
//     int pivot=partition(arr,start,end);
//     quickSort(arr,start,pivot-1);
//     quickSort(arr,pivot+1,end);
//     }
// }

// int main(){
//     vector<int>arr={5,2,6,4,1,3,-9};
//     int n=arr.size();
//     quickSort(arr,0,n-1);
//     for(int x:arr){
//         cout<<x<<" ";
//     }
// }
