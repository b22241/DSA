#include <cmath>
#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;


// vector<vector<int>> sumSubarrays(int arr[], int n, int target) {            //O(n2)
//     vector<vector<int>> ans;
//     for (int start = 0; start < n; start++) {
//         int sum = 0;
//         vector<int> element;
//         for (int i = start; i < n; i++) {
//             sum += arr[i];
//             element.push_back(arr[i]);
//             if (sum == target) {
//                 ans.push_back(element);
//             }
//         }
//     }
//     return ans;
// }


int sumSubarrays(int arr[], int n, int target) {   // O(n^2)
    vector<int> prefix_sum;
    int count = 0;
    int sum = 0;
    unordered_map<int,int> m;

    for (int i = 0; i < n; i++) {  
        sum = sum + arr[i];
        prefix_sum.push_back(sum);
    }

    for (int i = 0; i < n; i++) {
        int val = prefix_sum[i] - target;

        if (prefix_sum[i] == target) {   // direct match
            count++;
        }
        if (m.find(val) != m.end()) {    // found subarray sum
            count += m[val];
        }
        else{
            m[prefix_sum[i]]++;  // store current prefix sum
        }
    }
    return count;
}



int main() {
    int arr[] = {9, 4, 0, 20, 3, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 33;

    // vector<int> result=sumsub_array(arr,n,target);
    // for(int val:result){
    //     cout<< val<<" ";
    // }
    cout<<sumSubarrays(arr,n,target);


    // vector<vector<int>> result = sumSubarrays(arr, n, target);

    // // Print results
    // for (const auto& subarray : result) {
    //     cout << "[";
    //     for (size_t i = 0; i < subarray.size(); i++) {
    //         cout << subarray[i] << (i == subarray.size() - 1 ? "" : ", ");
    //     }
    //     cout << "]\n";
    // }

    // return 0;
}