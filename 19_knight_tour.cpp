#include <bits/stdc++.h>
using namespace std;


bool isValid(vector<vector<int>>& grid, int row, int col,int n,int num) {

    // First: invalid cases
    if (row < 0 || col < 0 || row >= n || col >= n || grid[row][col]!=num) return false;
    
    // Base case: last number matched
    if (num == (n * n) - 1) return true;

    // Try all knight moves
    int ans1=isValid(grid,row-2,col+1,n,num+1);
    int ans2=isValid(grid,row-1,col+2,n,num+1);
    int ans3=isValid(grid,row+1,col+2,n,num+1);
    int ans4=isValid(grid,row+2,col+1,n,num+1);
    int ans5=isValid(grid,row+2,col-1,n,num+1);
    int ans6=isValid(grid,row+1,col-2,n,num+1);
    int ans7=isValid(grid,row-1,col-2,n,num+1);
    int ans8=isValid(grid,row-2,col-1,n,num+1);

    return ans1||ans2||ans3||ans4||ans5||ans5||ans6||ans7||ans8;
}


int main() {
    vector<vector<int>> grid = {
        {0,11,16,5,20},
        {17,4,19,10,15},
        {12,1,8,21,6},
        {3,18,23,14,9},
        {24,13,2,7,22}
    };

    bool ans = isValid(grid, 0, 0,grid.size(), 0);
    cout << (ans ? "Valid tour" : "Not valid") << endl;
    return 0;
}

