#include <cmath>
#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//check if arr is sorted
// bool isSorted(vector<int>vec,int index){   
//     int n=vec.size();
//     if(index==n-1) return true;
//     return isSorted(vec,index+1) && vec[index+1]>=vec[index];
//     return false;
// }

//print all subsets of an array
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

//if values are repeating in arr,we can store values in set , set stores uniwure values
void printSubsets(vector<int> &arr, set<vector<int>> &ans, int i,vector<int>&subset) {              // //O(2^n*n)
    // Base case: when i reaches the end of arr
    if (i == arr.size()) {
        ans.insert(subset);
        return;
    }
    // Include the current element in subset
    subset.push_back(arr[i]);
    printSubsets(arr, ans, i + 1,subset);

    // Exclude the current element from subset (backtracking)
    subset.pop_back();
    printSubsets(arr, ans, i + 1,subset);
}

int main() {
    vector<int> arr = {1, 2, 2}; // Input set
    set<vector<int>> ans; // To store subsets
    vector<int>subset;
    // cout<<isSorted(arr,0);
    printSubsets(arr, ans, 0,subset);
    for(auto &vec:ans){
        for(auto  val:vec){
            cout<<val<<" ";
        }
        cout<<endl;
    }
}




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
