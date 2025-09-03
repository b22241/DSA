#include <cmath>
#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;


//O(n2)
// vector<vector<int>> sumSubarrays(int arr[], int n, int target) {
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

vector<vector<int>> sumSubarrays(int arr[], int n, int target){
    vector<int> prefix_sum;
    int cout=0;
    int sum=0;
    for (int i = 0; i < n; i++) {  
        sum = sum+arr[i];
        prefix_sum.push_back(sum);
    }
    for (int j=1;j<n;j++){
        int a=prefix_sum[j]-target;
        if(target==prefix_sum[j]){
            cout++;
            continue;
        }
        for(int l=0;l<j;l++){
            if(prefix_sum[l]==a){
                cout++;
                break;
            }
        }
    }
    return count;
    
}

int main() {
    int arr[] = {9, 4, 20, 3, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 33;

    vector<int> result=sumsub_array(arr,n,target);
    for(int val:result){
        cout<< val<<" ";
    }


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