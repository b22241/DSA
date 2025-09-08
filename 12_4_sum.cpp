#include <cmath>
#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;


vector<vector<int>> four_Sum(vector<int>& nums, int tar) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;  // skip duplicates

        for (int j = i + 1; j < n; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;  // skip duplicates

            int k = j + 1, l = n - 1;
            while (k < l) {
                long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                if (sum == tar) {
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++;
                    l--;

                    while (k < l && nums[k] == nums[k - 1]) k++;  // skip dups
                    while (k < l && nums[l] == nums[l + 1]) l--;  // skip dups
                }
                else if (sum < tar) {
                    k++;
                } else {
                    l--;
                }
            }
        }
    }
    return ans;
}

int main() {
    vector<int> vec = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> result = four_Sum(vec, target);

    for (auto quad : result) {
        for (auto val : quad) cout << val << " ";
        cout << endl;
    }
}
