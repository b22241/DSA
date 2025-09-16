#include <bits/stdc++.h>
using namespace std;


bool isvalid(vector<vector<int>>& grid, int num, int row, int col) {
    int n = grid.size();

    // First: invalid cases
    if (row < 0 || col < 0 || row >= n || col >= n || grid[row][col]!=num) return false;
    
    // Base case: last number matched
    if (num == (n * n) - 1) return true;

    // Try all knight moves
    return isvalid(grid, num + 1, row + 1, col - 2) ||
           isvalid(grid, num + 1, row - 2, col - 1) ||
           isvalid(grid, num + 1, row + 2, col + 1) ||
           isvalid(grid, num + 1, row + 1, col + 2) ||
           isvalid(grid, num + 1, row - 1, col + 2) ||
           isvalid(grid, num + 1, row - 2, col + 1) ||
           isvalid(grid, num + 1, row - 2, col - 1) ||
           isvalid(grid, num + 1, row - 1, col - 2);
}


int main() {
    vector<vector<int>> grid = {
        {0,11,16,5,20},
        {17,4,19,10,15},
        {12,1,8,21,6},
        {3,18,23,14,9},
        {24,13,2,7,22}
    };

    bool ans = isvalid(grid, 0, 0, 0);
    cout << (ans ? "Valid tour" : "Not valid") << endl;
    return 0;
}

