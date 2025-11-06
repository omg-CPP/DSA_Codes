#include <iostream>
#include <vector>
using namespace std;

void print2DVector(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

// M-3 : Without using any extra space
// Could you devise a constant space solution?
// Refer to Set Matrix Zeros of Leetcode with 3 Approaches
void booleanMatrix(vector<vector<int>>& matrix) {
    // code here
    int m = matrix.size();
    int n = matrix[0].size();

    bool zerothRow = false; // false : no one in 0th row
    bool zerothCol = false; // false : no one in 0th column

    for(int j = 0 ; j < n ; j++) {
        if(matrix[0][j] == 1) {
            zerothRow = true;
            break;
        }
    }
    for(int i = 0 ; i < m ; i++) {
        if(matrix[i][0] == 1) {
            zerothCol = true;
            break;
        }
    }

    for(int i = 1 ; i < m ; i++) {
        for(int j = 1 ; j < n ; j++) {
            if(matrix[i][j] == 1) {
                matrix[0][j] = 1; // change in column vector
                matrix[i][0] = 1; // change in row vector
            }
        }
    }

    for(int j = 1 ; j < n ; j++) { // traversing column vector
        if(matrix[0][j] == 1) {
            for(int i = 1 ; i < m ; i++) {
                matrix[i][j] = 1;
            }
        }
    }

    for(int i = 1 ; i < m ; i++) { // traversing row vector
        if(matrix[i][0] == 1) {
            for(int j = 1 ; j < n ; j++) {
                matrix[i][j] = 1;
            }
        }
    }

    // checking one in 0th row
    if(zerothRow == true) {
        for(int j = 0 ; j < n ; j++) {
            matrix[0][j] = 1;
        }
    }

    // checking one in 0th column
    if(zerothCol == true) {
        for(int i = 0 ; i < m ; i++) {
            matrix[i][0] = 1;
        }
    }
    return;
}

int main()
{
    vector<vector<int>> arr = {{1,0,0},{1,0,0},{1,0,0},{0,0,0}};
    print2DVector(arr);
    // 1 0 0 
    // 1 0 0 
    // 1 0 0 
    // 0 0 0 
    booleanMatrix(arr);
    print2DVector(arr);
    // 1 1 1 
    // 1 1 1 
    // 1 1 1 
    // 1 0 0 
    return 0;
}