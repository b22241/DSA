#include <cmath>
#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;


// //O(2^n*n)
// void printSubsets(vector<int> &arr, vector<int> &ans, int i) {
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

// int main() {
//     vector<int> arr = {1, 2, 3}; // Input set
//     vector<int> ans; // To store subsets

//     printSubsets(arr, ans, 0);

//     return 0;
// }




class Solution {
public:
    set<vector<int>> s;

    void allcombination(vector<int>& arr, int idx, int target, vector<int>& combination, vector<vector<int>>& ans) {
        if (idx == arr.size() || target < 0) {
            return;
        }

        if (target == 0) {
            if (s.find(combination) == s.end()) { // Fixed missing parenthesis
                ans.push_back(combination); // Fixed incorrect insertion
                s.insert(combination);
            }
            return;
        }

        // Include the current element (single occurrence)
        combination.push_back(arr[idx]);
        allcombination(arr, idx + 1, target - arr[idx], combination, ans);

        // Include the current element (multiple occurrences)
        allcombination(arr, idx, target - arr[idx], combination, ans);

        // Exclude the current element (backtracking)
        combination.pop_back();
        allcombination(arr, idx + 1, target, combination, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> combination;
        allcombination(arr, 0, target, combination, ans);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = sol.combinationSum(arr, target);

    // Print the result
    for (auto vec : result) {
        cout << "[ ";
        for (int num : vec) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
