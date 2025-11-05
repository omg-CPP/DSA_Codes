#include <iostream>
#include <vector>
using namespace std;

int matrixScore(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    // making the first column all 1's
    for(int i = 0 ; i < rows ; i++) {
        if(grid[i][0] == 0) { // row flip
            for(int j = 0 ; j < cols ; j++) {
                if(grid[i][j] == 0) {
                    grid[i][j] = 1;
                }
                else { // grid[i][j] == 1
                    grid[i][j] = 0;
                }
            }
        }
    }

    // flipping the columns where noOfZeros > noOfOnes
    for(int j = 1 ; j < cols ; j++) {
        int noOfZeros = 0;
        int noOfOnes = 0;
        for(int i = 0 ; i < rows ; i++) {
            if(grid[i][j] == 0) {
                noOfZeros++;
            }
            else { // grid[i][j] == 1
                noOfOnes++;
            }
        }
        if(noOfZeros > noOfOnes) { // column flip
            for(int i = 0 ; i < rows ; i++) {
                if(grid[i][j] == 0) {
                    grid[i][j] = 1;
                }
                else { // grid[i][j] == 1
                    grid[i][j] = 0;
                }
            }
        }
    }

    for(int i = 0 ; i < rows ; i++) {
        for(int j = 0 ; j < cols ; j++) {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }

    // Binary to Decimal Conversion
    int sum = 0;
    for(int i = 0 ; i < rows ; i++) {
        int x = 1;
        for(int j = cols-1 ; j >= 0 ; j--) {
            sum = sum + (grid[i][j]*x);
            x = x*2;
        }
    }
    return sum;
}

int main()
{
    vector<vector<int>> matrix = {{0,0,1,1},{1,0,1,0},{1,1,0,0}};
    int score = matrixScore(matrix);
    cout<<"The Score after Flipping the Matrix is : "<<score<<endl;
    // The Score after Flipping the Matrix is : 39

    vector<vector<int>> mat = {{0,1,1},{1,1,1},{0,1,0}};
    int ans = matrixScore(mat);
    cout<<"The Score after Flipping the Matrix is : "<<ans<<endl;
    // The Score after Flipping the Matrix is : 18
    return 0;
}

// 1 1 1 1 
// 1 0 0 1 
// 1 1 1 1 
// The Score after Flipping the Matrix is : 39
// 1 1 0 
// 1 0 1 
// 1 1 1 
// The Score after Flipping the Matrix is : 18