#include <iostream>
#include <vector>
#include <stack>
#include<climits>
#include <numeric>
#include <algorithm> 
#include <bits/stdc++.h>
using namespace std;

//O(n2)
vector<int> max_SlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n-k+1;i++){
            int maximum=INT_MIN;
            for(int j=i;j<i+k;j++){
                maximum=max(maximum,nums[j]);
            }
            ans.push_back(maximum);
        }
        return ans;
    }

//O(n)--using hashmap
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq; // will store indices
    vector<int> res;

    // Process first k elements
    for (int i = 0; i < k; i++) {
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    // Process the rest of the array
    for (int i = k; i < nums.size(); i++) {
        // The front of the deque is the largest element's index for the previous window
        res.push_back(nums[dq.front()]);

        // Remove elements not part of current window
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Remove all smaller elements as they are useless
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    // Add the maximum for the last window
    res.push_back(nums[dq.front()]);

    return res;
}

int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> res = maxSlidingWindow(nums, k);

    for (int x : res) cout << x << " ";
}

