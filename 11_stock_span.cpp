#include<iostream>
#include<vector>
#include<climits>
#include<stack>
#include <algorithm>
using namespace std;

vector<int> stock_span(vector<int> price) {
    stack<int> s;
    vector<int> ans;
    s.push(0);             
    ans.push_back(1);     

    for (int i = 1; i < price.size(); i++) {
        while (!s.empty() && price[s.top()] <= price[i]) {
            s.pop();
        }
        if (s.empty()) {
            ans.push_back(i + 1);
        } else {
            ans.push_back(i - s.top());
        }
        s.push(i); 
    }
    return ans;
}

vector<int>next_greater_element(vector<int>arr){
    int n=arr.size();
    vector<int>ans(n,1);
    ans[n-1]=-1;
    stack<int>s;
    s.push(arr[n-1]);
    for(int i=arr.size()-2;i>=0;i--){
        if(s.top()>arr[i]){
            ans[i]=s.top();
        }
        else{
            while(!s.empty()&& s.top()<arr[i]){
                s.pop();
            }
            if(s.size()==0){
                ans[i]=-1;
            }
            s.push(arr[i]);
        }
    }
    return ans;
}

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> NSL(n), NSR(n);
        stack<int> s;

        // Next Smaller to Left
        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            if (s.empty()) {
                NSL[i] = 0;
            } else {
                NSL[i] = s.top();
            }
            s.push(i);
        }

        // Clear stack before NSR
        while (!s.empty()) s.pop();

        // Next Smaller to Right
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            if (s.empty()) {
                NSR[i] = n-1;
            } else {
                NSR[i] = s.top();
            }
            s.push(i);
        }

        // Debug print: NSL
        cout << "Left Boundry: ";
        for (int i = 0; i < n; i++) cout << NSL[i] << " ";
        cout << endl;

        cout << "Right Boundry: ";
        for (int i = 0; i < n; i++) cout << NSR[i] << " ";
        cout << endl;

        // Calculate area
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = NSR[i] - NSL[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }

        cout << "Max Area: " << maxArea << endl;
        return maxArea;
    }
};

//brute force(O(n2))
int trapping_rainwater(vector<int> arr) {
    int n = arr.size();
    vector<int> left_max(n), right_max(n);

    // Fill left_max
    left_max[0] = arr[0];
    for (int i = 1; i < n; i++) {
        left_max[i] = max(left_max[i - 1], arr[i]);
    }

    // Fill right_max
    right_max[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        right_max[i] = max(right_max[i + 1], arr[i]);
    }

    // Calculate water trapped
    int area = 0;
    for (int i = 0; i < n; i++) {
        int water_height = min(left_max[i], right_max[i]) - arr[i];
        if (water_height > 0) {
            area += water_height;
        }
    }
    return area;
}

int celebrity(vector<vector<int>>arr){
    stack<int>s;
    int n=arr.size();
    for(int i=0;i<n;i++){
        s.push(i);
    }

    while(s.size()>1){
        int i=s.top(); s.pop();
        int j=s.top(); s.pop();
        if(arr[i][j]==0){
            s.push(i);
        }
        else{
            s.push(j);
        }
    }
    int celeb=s.top();
    s.pop();
    for(int i=0;i<n;i++){
        if (i != celeb && (arr[i][celeb] == 0 || arr[celeb][i] == 1)){
            return -1;
        }
        else{
            return celeb;
        }
    }
}


int main() {
    // vector<int> price = {100, 80, 60, 70, 60, 75, 85};
    // vector<int> ans = stock_span(price);
    // for (int val : ans) {
    //     cout << val << " ";
    // }

    // vector<int>arr={6,8,0,1,3};
    // vector<int>ans=next_greater_element(arr);
    // for(int x:ans){
    //     cout<<x<<",";
    // }

    // Solution sol;
    // vector<int> heights = {2, 1, 5, 6, 2, 3};
    // sol.largestRectangleArea(heights);
   
    // vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    // cout << trapping_rainwater(arr) << endl;

    // vector<vector<int>> arr = {
    //     {0, 1, 0},
    //     {0, 0, 0},
    //     {0, 1, 0}
    // };
    // int result = celebrity(arr);
    // if (result == -1) {
    //     cout << "No celebrity found" << endl;
    // } else {
    //     cout << "Celebrity is person: " << result << endl;
    // }
}
