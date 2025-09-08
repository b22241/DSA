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

// pair<int,int> twoSum(vector<int>arr,int target){
//     int n=arr.size();
//     unordered_map<int, int> m;
//     for(int i=0;i<n;i++){
//         int first=arr[i];
//         int second=target-arr[i];
//         if(m.find(second)!=m.end()){
//             return {i,m[second]};
//         }
//         else{
//             m[first]=i;
//         }
//     }
//     return {-1,-1};
// }

// pair<int,int> missingRepeating(vector<vector<int>> &mat){
//     unordered_set<int> s;
//     int repeating = -1;
//     long long sum = 0;
//     int n = mat.size(); 
//     for(int i=0; i<n; i++){
//         for(int j=0; j<mat[i].size(); j++){
//             if(s.find(mat[i][j]) != s.end()){
//                 repeating = mat[i][j];
//             }
//             else{
//                 s.insert(mat[i][j]);
//             }
//             sum += mat[i][j];
//         }
//     }
//     long long expected = 1LL * n * n * (n*n + 1) / 2;
//     int missing = (int)(expected - (sum - repeating));
//     return {repeating, missing};
// }

// time and space complexity--O(n)
// int duplicate(vector<int>vec){
//     unordered_set<int> s;
//     for(int i=0;i<vec.size();i++){
//         if(s.find(vec[i])!=s.end()){
//             return vec[i];
//             exit;
//         }
//         s.insert(vec[i]);
//     }
// }

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
    vector<vector<int>> mat={{9,1,7},{8,9,2},{3,4,6}};
    vector <int> arr={2,7,11,15};
    // vector <int> vec={1,2,3,3,4};

    // int n=sizeof(arr) / sizeof(arr[0]);
    // int target=17;
    // pair<int, int> result = twoSum(arr, target);
    // cout << result.first << " " << result.second << endl;
    // vector<int> result = twoSum(arr, target);
    // for (int i : result) {
    //     cout << i << " ";
    // }
    // pair<int, int> result = missingRepeating(mat);
    // cout << result.first << " " << result.second << endl;
    // cout << "Missing Value: " << result[0] << ", Repeating Value: " << result[1] << endl;
    // vector<int> result = duplicate_value(vec);
    // cout<<result[0];

    cout<<duplicate(vec);
}
