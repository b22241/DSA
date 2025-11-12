#include<bits/stdc++.h>
using namespace std;

// the idea is to visit every cell and and if it's neighboring cells are visited then keep on visiting neihoring cells.job of dfs function is to mark true in visited where 1 is there in board.
//after this 1 island is formned , and we well call next cell and next island will fomr.
void dfs(vector<vector<int>>board,vector<vector<bool>>&visited,int i,int j){
        if(i<0||j<0||i>=board.size() || j>board.size()) return;
        if(board[i][j]==0) return;
        if(visited[i][j]==true) return;


        visited[i][j]=true;
        dfs(board,visited,i-1,j);
        dfs(board,visited,i,j+1);
        dfs(board,visited,i+1,j);
        dfs(board,visited,i,j-1);
      
    }
int visitIsland(vector<vector<int>>board,vector<vector<bool>>&visited){
    int island=0;
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==false && board[i][j]==1){
                    dfs(board,visited,i,j);
                    island++;
                }
            }
        }
        return island;
}

int main(){  
         vector<vector<int>>board={
        {1,1,0,0,0},
        {1,1,0,0,0},
        {0,0,1,0,0},
        {0,0,0,1,1}};
        vector<vector<bool>>visited={
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}};
        cout<<visitIsland(board,visited);
}