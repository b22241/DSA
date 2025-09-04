#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
using namespace std;

//Function to find the max rainwater that can be trapepd
// int ranwater(vector<int> v) {
//     int ans = 0;
//     int left = 0;
//     int right = v.size() - 1;
//     int lmax = 0;
//     int rmax = 0;
//     while (left < right) {
//         lmax = max(lmax, v[left]);
//         rmax = max(rmax, v[right]);
//         if (lmax < rmax) {
//             ans = ans + (lmax - v[left]);
//             left++;
//         } else {
//             ans = ans + (rmax - v[right]);
//             right--;
//         }
//     }
//     return ans;
// }

// int main() {
//     vector<int> v = {4, 2, 0, 3, 2, 5};
//     cout << ranwater(v);
// }


// Function to find the celebrity
// int findCelebrity(vector<vector<int>>& arr) {
//     stack<int> s;
//     int n=arr.size();
//     // Step 1: Push all people onto the stack
//     for (int i = 0; i < n; i++) {
//         s.push(i);
//     }
//     // Step 2: Eliminate non-celebrities
//     while (s.size() > 1) {
//         int i = s.top(); s.pop();
//         int j = s.top(); s.pop();
//         if (arr[i][j] == 0) {
//             // i does not know j -> j can't be celebrity
//             s.push(i);
//         } else {
//             // i knows j -> i can't be celebrity
//             s.push(j);
//         }
//     }
//     // Step 3: Potential celebrity
//     int celeb = s.top();
//     // Step 4: Verify if the candidate is a celebrity
//     for (int i = 0; i < n; i++) {
//         if (i != celeb && (arr[i][celeb] == 0 || arr[celeb][i] == 1)) {
//             return -1; // Not a celebrity
//         }
//     }
//     return celeb; // Celebrity found
// }

// int main() {
//     vector<vector<int>> arr={{0,1,0},{0,0,1},{0,1,0}};
//     cout<<findCelebrity(arr);
//     return 0;
// }


//sliding window problem


// vector<int> sliding_window(vector<int> window){
//     int n = window.size();
//     vector<int> output;

//     // Sliding window of size 3
//     for(int i = 0; i <= n - 3; i++){
//         int max_val1 = max(window[i], window[i+1]);
//         int max_val2 = max(window[i+2],max_val1);
//         output.push_back(max_val2); 
//     }
//     return output;
// }

// int main(){
//     vector<int> window = {1, 3, -1, -3, 5, 3, 6, 7};
//     vector<int> ans = sliding_window(window);
//     for (int x : ans)
//         cout << x << " ";
//         return 0;
// }




int gas_station(vector<int> gas, vector<int> cost){
    int n = gas.size();
    int previous_fuel = 0;
    int start = 0;

    if(accumulate(gas.begin(), gas.end(), 0)>=accumulate(cost.begin(), cost.end(), 0)){
        for(int i = 0; i < n; i++) {
        previous_fuel = previous_fuel+gas[i] - cost[i];
        if(previous_fuel < 0) {
            start = i + 1;
            previous_fuel = 0;
        }
    }
    return start;
    }
    return -1;
}

int main() {
    vector<int> gas = {1, 2, 4, 5, 9};
    vector<int> cost = {3, 4, 1, 10, 1};

    int start_station = gas_station(gas, cost);
    if (start_station != -1)
        cout << "Start at station: " << start_station << endl;
    else
        cout << "No valid starting station" << endl;

    return 0;
}