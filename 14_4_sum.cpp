#include <cmath>
#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;



vector<vector<int>> fourSum(vector<int>& nums, int tar) {
    vector<vector<int>> ans;
    int n = nums.size();

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;  // Skip duplicates for i

        for (int j = i + 1; j < n; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;  // Skip duplicates for j

            int p = j + 1, q = n - 1;

            while (p < q) {
                long long sum = (long long)nums[i] + (long long)nums[j] + 
                                (long long)nums[p] + (long long)nums[q];

                if (sum < tar) {
                    p++;
                } 
                else if (sum > tar) {
                    q--;
                } 
                else {  // sum == tar
                    ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                    p++;
                    q--;

                    // Skip duplicates for p and q
                    while (p < q && nums[p] == nums[p - 1]) p++;
                    while (p < q && nums[q] == nums[q + 1]) q--;
                }
            }
        }
    }
    return ans;
}  



int main(){

    vector<int> vec = {1, 0, -1, 0, -2, 2};
    int target=0;
    vector<vector<int>> result = fourSum(vec,target);
    for (const auto& quadruplet : result) {
        cout << "[";
        for (size_t i = 0; i < quadruplet.size(); i++) {
            cout << quadruplet[i] << (i == quadruplet.size() - 1 ? "" : ", ");
        }
        cout << "]\n";
    }
    return 0;
    
    
}