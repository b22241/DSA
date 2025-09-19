#include <bits/stdc++.h>
using namespace std;

//O(n2)                           //-------------------------------sliding window---------------------------
// vector<int> max_SlidingWindow(vector<int>& nums, int k) {
//         int n=nums.size();
//         vector<int>ans;
//         for(int i=0;i<n-k+1;i++){
//             int maximum=INT_MIN;
//             for(int j=i;j<i+k;j++){
//                 maximum=max(maximum,nums[j]);
//             }
//             ans.push_back(maximum);
//         }
//         return ans;
//     }

// //O(n)--using hashmap
// void slidingWindow(vector<int>window,int k){
//         deque<int> q;
//         int n = window.size();
//         vector<int> ans;
//         for (int i = 0; i < k; i++) {
//             while (!q.empty() && window[i] >= window[q.back()]) {
//                 q.pop_back();
//             }
//             q.push_back(i); // store index
//         }
//         ans.push_back(window[q.front()]);
//         // process rest
//         for (int i = k; i < n; i++) {
//             // remove out of window index
//             while (!q.empty() && q.front() <= i - k) {
//                 q.pop_front();
//             }
//             // maintain decreasing order
//             while (!q.empty() && window[i] >= window[q.back()]) {
//                 q.pop_back();
//             }
//             q.push_back(i);
//             // front is max
//             ans.push_back(window[q.front()]);
//         }
//     for(int val:ans){
//         cout<<val<<" ";
//     }
// }


// int main(){
//     vector<int>window={1,3,-1,-3,5,3,6,7};
//     int k=3;
//    slidingWindow(window,k);
// }

// int main() {
//     vector<int> nums = {1,3,-1,-3,5,3,6,7};
//     int k = 3;
//     vector<int> res = maxSlidingWindow(nums, k);

//     for (int x : res) cout << x << " ";
// }




                      //--------------gas station------------------ (greedy search)
// int gas_station(vector<int> gas, vector<int> cost){
//     int n = gas.size();
//     int previous_fuel = 0;
//     int start = 0;

//     if(accumulate(gas.begin(), gas.end(), 0)>=accumulate(cost.begin(), cost.end(), 0)){
//         for(int i = 0; i < n; i++) {
//         previous_fuel = previous_fuel+gas[i] - cost[i];
//         if(previous_fuel < 0) {
//             start = i + 1;
//             previous_fuel = 0;
//         }
//     }
//     return start;
//     }
//     return -1;
// }

// int main() {
//     vector<int> gas = {1, 2, 4, 5, 9};
//     vector<int> cost = {3, 4, 1, 10, 1};

//     int start_station = gas_station(gas, cost);
//     if (start_station != -1)
//         cout << "Start at station: " << start_station << endl;
//     else
//         cout << "No valid starting station" << endl;

//     return 0;
// }

