#include <iostream>
#include <vector>
using namespace std;

// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// You must do it in place.

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

// M-1 : By creating an extra 2D array
// Space Complexity : O(m*n)
// A straightforward solution using O(mn) space is probably a bad idea.
void setZeroesBruteForce(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> copy(m,vector<int>(n));
    // creating copy of matrix
    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            copy[i][j] = matrix[i][j];
        }
    }
    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            if(copy[i][j] == 0) {
                // set 0's at ith row
                // row constant
                for(int c = 0 ; c < n ; c++) {
                    matrix[i][c] = 0;
                }
                // set 0's at jth column
                // column constant
                for(int r = 0 ; r < m ; r++) {
                    matrix[r][j] = 0;
                }
            }
        }
    }
    return;
}

// M-2 : Using 2 1D arrays of m and n lenght
// A simple improvement uses O(m + n) space, but still not the best solution.
void setZeroesBetter(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<bool> row(m,false);
    vector<bool> col(n,false);

    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            if(matrix[i][j] == 0) {
                // true means 0 set karna hai
                row[i] = true;
                col[j] = true;
            }
        }
    }
    // set matrix zeros

    // setting rows zero
    for(int i = 0 ; i < m ; i++) {
        if(row[i] == true) {
            // row -> constant
            for(int j = 0 ; j < n ; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    // setting rows zero
    for(int j = 0 ; j < n ; j++) {
        if(col[j] == true) {
            // column -> constant
            for(int i = 0 ; i < m ; i++) {
                matrix[i][j] = 0;
            }
        }
    }
    return;
}

// M-3 : Without using any extra space
// Could you devise a constant space solution?
void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    bool zerothRow = false; // false : no zero in 0th row
    bool zerothCol = false; // false : no zero in 0th column

    for(int j = 0 ; j < n ; j++) {
        if(matrix[0][j] == 0) {
            zerothRow = true;
            break;
        }
    }
    for(int i = 0 ; i < m ; i++) {
        if(matrix[i][0] == 0) {
            zerothCol = true;
            break;
        }
    }

    for(int i = 1 ; i < m ; i++) {
        for(int j = 1 ; j < n ; j++) {
            if(matrix[i][j] == 0) {
                matrix[0][j] = 0; // change in column vector
                matrix[i][0] = 0; // change in row vector
            }
        }
    }

    for(int j = 1 ; j < n ; j++) { // traversing column vector
        if(matrix[0][j] == 0) {
            for(int i = 1 ; i < m ; i++) {
                matrix[i][j] = 0;
            }
        }
    }

    for(int i = 1 ; i < m ; i++) { // traversing row vector
        if(matrix[i][0] == 0) {
            for(int j = 1 ; j < n ; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    // checking zero in 0th row
    if(zerothRow == true) {
        for(int j = 0 ; j < n ; j++) {
            matrix[0][j] = 0;
        }
    }

    // checking zero in 0th column
    if(zerothCol == true) {
        for(int i = 0 ; i < m ; i++) {
            matrix[i][0] = 0;
        }
    }
    return;
}

int main()
{
    vector<vector<int>> arr = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    print2DVector(arr);
    // 0 1 2 0 
    // 3 4 5 2 
    // 1 3 1 5 
    setZeroesBruteForce(arr);
    print2DVector(arr);
    // 0 0 0 0 
    // 0 4 5 0 
    // 0 3 1 0 

    vector<vector<int>> brr = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    print2DVector(brr);
    // 0 1 2 0 
    // 3 4 5 2 
    // 1 3 1 5 
    setZeroesBetter(brr);
    print2DVector(brr);
    // 0 0 0 0 
    // 0 4 5 0 
    // 0 3 1 0 

    vector<vector<int>> crr = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    print2DVector(crr);
    // 0 1 2 0 
    // 3 4 5 2 
    // 1 3 1 5 
    setZeroes(crr);
    print2DVector(crr);
    // 0 0 0 0 
    // 0 4 5 0 
    // 0 3 1 0 
    
    return 0;
}