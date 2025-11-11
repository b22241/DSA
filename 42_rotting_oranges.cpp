#include <bits/stdc++.h>
using namespace std;

int bfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int n, int m) {
    queue<pair<pair<int,int>,int>> q;
    int ans = 0;

    // Push all initially rotten oranges
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 2){
                q.push({{i,j},0});
                visited[i][j] = true;
            }
        }
    }

    // BFS traversal
    while(!q.empty()){
        int i = q.front().first.first;
        int j = q.front().first.second;
        int time = q.front().second;
        q.pop();

        ans = max(ans,time);

        if(i-1 >= 0 && !visited[i-1][j] && grid[i-1][j] == 1){
            q.push({{i-1,j},time+1});
            visited[i-1][j] = true;
        }
        if(i+1 < n && !visited[i+1][j] && grid[i+1][j] == 1){
            q.push({{i+1,j},time+1});
            visited[i+1][j] = true;
        }
        if(j+1 < m && !visited[i][j+1] && grid[i][j+1] == 1){
            q.push({{i,j+1},time+1});
            visited[i][j+1] = true;
        }
        if(j-1 >= 0 && !visited[i][j-1] && grid[i][j-1] == 1){
            q.push({{i,j-1},time+1});
            visited[i][j-1] = true;
        }
    }

    // Check if any fresh oranges remain
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 1 && !visited[i][j]){
                return -1;
            }
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m,false));
    cout << bfs(grid, visited, n, m) << endl;
}
