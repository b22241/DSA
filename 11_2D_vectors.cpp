#include <cmath>
#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
using namespace std;


//can have different different row or column sixes
int main(){
    vector<vector<int>> mat={{1,2,3},{4,5,6,2,8},{7,8,9}};
    //int rows=mat.size();
    //int cols=mat[i].size();
    for(int i=0;i<mat.size();i++){
        for (int j=0;j<mat[i].size();j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

}