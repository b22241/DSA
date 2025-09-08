#include <cmath>
#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;


// vector<int> two_sum(int arr[],int n,int target)
// {
//     vector<int> output; 
//         for (int i = 0; i < n; i++) 
//         {
//             for (int j = i + 1; j < n;j++) 
//             { 
//                 if (arr[i] + arr[j] == target) 
//                 {
//                     output.push_back(i);
//                     output.push_back(j);
//                     return output;
//                 }
//             }
//         }
// }

vector<int>

// vector<int> twoSum(vector<int>& arr, int tar) {
//     unordered_map<int, int> m;
//     vector<int> ans;

//     for (int i = 0; i < arr.size(); i++) {
//         int first = arr[i];
//         int sec = tar - first;

//         if (m.find(sec) != m.end()) {
//             ans.push_back(i);
//             ans.push_back(m[sec]);
//             break;
//         }

//         m[first] = i;
//     }

//     return ans;
// }

// vector<int> missing_repeating(vector<vector<int>>& mat) {
//     vector<int> freq(9, 0); // Frequency array for numbers 1-9
//     int missing_value = -1, repeating_value = -1;

//     // Count frequency of each number in the matrix
//     for (int i = 0; i < mat.size(); i++) {
//         for (int j = 0; j < mat[i].size(); j++) {
//             int value = mat[i][j];
//             freq[value - 1]++; // Increase frequency count
//         }
//     }
//      // Find missing and repeating numbers
//     for (int i = 0; i < 9; i++) {
//         if (freq[i] == 0) {
//             missing_value = i + 1; // Missing number (1-based index)
//         }
//         if (freq[i] == 2) {
//             repeating_value = i + 1; // Repeating number
//         }
//     }

//     return {missing_value, repeating_value};
// }

vector<int> duplicate_value(vector<int> &vector){
    unordered_set<int> s;
    for( int val:vector){
        if(s.find(val)!=s.end()){
            return {val};
        }
        s.insert(val);
    }
}

//O(1) space complexity
int findDuplicate(vector<int>& arr)
{
    int slow = arr[0], fast = arr[0];

// Phase 1: Finding the intersection point using Floyd’s Cycle Detection Algorithm
do {
   slow = arr[slow];  // Moves one step
   fast = arr[arr[fast]];  // Moves two steps
} while (slow != fast);

// Phase 2: Finding the entrance to the cycle (duplicate number)
slow = arr[0];
while (slow != fast) {
   slow = arr[slow];  // Moves one step
   fast = arr[fast];  // Moves one step
}

return slow; // The duplicate number
}

int main(){
    // vector<vector<int>> mat={{9,1,7},{8,9,2},{3,4,6}};
    // vector <int> arr={2,7,11,15};
    vector <int> vec={1,2,3,3,4};

    // int n=sizeof(arr) / sizeof(arr[0]);
    // int target=9;
    // vector<int> result = twoSum(arr, target);
    // for (int i : result) {
    //     cout << i << " ";
    // }
    // vector<int> result = missing_repeating(mat);
    // cout << "Missing Value: " << result[0] << ", Repeating Value: " << result[1] << endl;
    vector<int> result = duplicate_value(vec);
    cout<<result[0];
}
