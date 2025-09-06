#include <cmath>
#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;



int get_maxRowsum(int mat[][3],int rows,int cols){
    int max_sum=INT_MIN;
    for (int i=0;i<rows;i++){
        int rowsum=0;
        for (int j=0;j<cols;j++){
            rowsum=rowsum+mat[i][j];
        }
        max_sum=max(max_sum,rowsum);
    }
    return max_sum;
}

int diagonal_sum(int mat[3][3],int rows,int cols){
    int i=0;
    int diagonal_sum=0;
    while(i<rows){
        diagonal_sum=diagonal_sum+mat[i][i]+mat[i][cols-i-1];
        i++;
    }
    if(rows%2==1) diagonal_sum=diagonal_sum-mat[rows/2][cols/2];
    return diagonal_sum;
}


pair<int, int> binarySearch(int mat[3][3], int rows, int cols, int target) {
    int i = 0;
    while (i < rows && mat[i][cols - 1] < target) {
        i++;
    }
    if (i >= rows) {
        return {-1, -1};
    }
    int start = 0, end = cols - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (mat[i][mid] == target) {
            return {i, mid};
        }
        else if (mat[i][mid] > target) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return {-1, -1};
}


int main(){
    int mat[4][3]={{1,2,3},{4,5,6},{7,8,9}};
    int rows=3;
    int cols=3;
    //cout<<matrix[1][1];
    // coutS<<get_maxRowsum(mat,rows, cols);
    //cout<<diagonal_sum(mat,rows, cols);
    int target = 8;
    pair<int, int> result = binarySearch(mat, 3, 3, target);

    // if (result.first != -1) {
    //     cout << target << " is present at row " << result.first << " and column " << result.second << endl;
    // } else {
    //     cout << target << " is not present in the matrix." << endl;
    // }

    return 0;
}