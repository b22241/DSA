#include<bits/stdc++.h>
using namespace  std;



// normal recursion
// int fib1(int n){
//     if(n<=1) return n;
//     return fib1(n-1)+fib1(n-2);
// }

// bottom up approach(optimised) with memorisation
// int fib2(int n,vector<int>&dp){
//     if(n<=1) return n;
//     if(dp[n]!=-1) return dp[n];

//     dp[n]=fib2(n-1,dp)+fib2(n-2,dp);
//     return dp[n];
// }

// top down approach(optimised)  with memorisation
// int fib3(int n,vector<int>&dp){
    
//     for(int i=2;i<=n;i++){
//         dp[i]=dp[i-1]+dp[i-2];
//     }
//     return dp[n];
// }

// 2 pointer approach(most optimisted) //tabulation method
// int fib4(int n){
//     int prev1=0;
//     int prev2=1;

//     for(int i=2;i<=n;i++){
//         int curr=prev1+prev2;
//         prev1=prev2;
//         prev2=curr;
//     }
//     return prev2;
// }

//  Maximum sum of non-adjacent elements
// int help(vector<int>& nums, int index,vector<int>&dp){
//     if(index >= nums.size()){
//         return 0;
//     }
//     if(index == nums.size()-1){
//         return nums[index];
//     }
//     if(dp[index]!=-1){
//         return dp[index];
//     }

//     int include=help(nums,index+2,dp)+nums[index];
//     int exclude=help(nums,index+1,dp)+0;
//     dp[index]= max(include,exclude);
//     return dp[index];
// }

// int houseRobber(vector<int>& arr)
// {
//     Write your code here.
//     int n=arr.size();

//     n is even
//     int a=0;
//     int b=0;
//     for(int i=0;i<n;i++){
//         if(i&1){
//             a=a+arr[i];
//         }
//         else if(i!=n-1){
//             b=b+arr[i];
//         }
//     }
//     return max(a,b);
// }
// int main(){
//     int n=5;
//     vector<int>dp(n+1,-1);
//     vector<int>dp(n+1);
//     dp[0]=0;
//     dp[1]=1;
//     cout<<fib4(n)
//     vector<int>nums={11,9,8,2};
//     vector<int>dp(nums.size()+1,-1);
//     cout<<help(nums,0,dp);
//     vector<int>arr= {1,2,3,4,5,6,7,8,9,10};
//     cout<<houseRobber(arr);

// }


// int solve(vector<vector<int>>& v, int row, int col, vector<vector<int>>& dp) {
//     if (row < 0 || row > 2)
//         return 1e9;
//     if (col == v[0].size() - 1)
//         return 0;
//     if (v[row][col] == 1)
//         return 1e9;
//     if (dp[row][col] != -1)
//         return dp[row][col];
    


//         int straight=INT_MAX;
//     if(col+1>v[0].size() - 1 && v[row][col]==0){
//         straight = solve(v, row, col + 1, dp);
//     }
    

//     // 2. Side Jumps
//     // LOGIC FIX: When we side jump, we must move forward (col + 1) in the recursive call 
//     // to prevent infinite loops (jumping up then jumping down forever).
//     // We also check if the lane we are jumping into is valid and not an obstacle.

//     int up1 = 1e9, up2 = 1e9, down1 = 1e9, down2 = 1e9;

//     // Move up 1 lane
//     if (row - 1 >= 0 && v[row - 1][col] == 0) 
//         up1 = 1 + solve(v, row - 1, col + 1, dp);

//     // Move up 2 lanes
//     if (row - 2 >= 0 && v[row - 2][col] == 0) 
//         up2 = 1 + solve(v, row - 2, col + 1, dp);

//     // Move down 1 lane
//     if (row + 1 <= 2 && v[row + 1][col] == 0) 
//         down1 = 1 + solve(v, row + 1, col + 1, dp);

//     // Move down 2 lanes
//     if (row + 2 <= 2 && v[row + 2][col] == 0) 
//         down2 = 1 + solve(v, row + 2, col + 1, dp);

//     // take min from all possible moves
//     int ans = min({straight, up1, up2, down1, down2});

//     return dp[row][col] = ans;
// }

// int main() {
//     // Example input
//     vector<int> obstacles = {0, 1, 2, 3, 0};
//     int m = obstacles.size();
    
//     // Create Grid
//     vector<vector<int>> v(3, vector<int>(m, 0));
//     for (int col = 0; col < m; col++) {
//         int lane = obstacles[col];
//         if (lane != 0) {
//             v[lane - 1][col] = 1;
//         }
//     }

//     // Init DP
//     vector<vector<int>> dp(3, vector<int>(m, -1));

//     // Print Result
//     // Start at Lane 2 (index 1), Col 0
//     cout << "Minimum Jumps: " << solve(v, 1, 0, dp) << endl;

//     return 0;
// }

int longest(vector<int>&v,int index){
    if(index==v.size()-1) return 0;
}

int main(){
    vector<int>v={10,6,3,7,15,21,0,0,0,25};

    int n=v.size();
    int len;
    int ans=1;
    int prev;
    for(int i=0;i<n;i++){
        ans=max(ans,len);
        len=1;
        prev=v[i];
        for(int j=i+1;j<n;j++){
            if(v[j]>prev) {
                len++;
                prev=v[j];
            }
        }
    }
    cout<<ans;
}