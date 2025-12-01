// GFG

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> prefixSum2D(vector<vector<int>>& grid) {
    // constructing a N*M grid
    int n = grid.size();     // no of rows
    int m = grid[0].size();  // no of columns
    vector<vector<int>> prefixSumGrid(n,vector<int>(m,0));

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            prefixSumGrid[i][j] = grid[i][j];
            // adding row-wise prefixSum
            if(i > 0) {
                prefixSumGrid[i][j] += prefixSumGrid[i-1][j];
            }
            // adding column-wise prefixSum
            if(j > 0) {
                prefixSumGrid[i][j] += prefixSumGrid[i][j-1];
            }
            // removing diagonal prefixSum
            if(i > 0 && j > 0) {
                prefixSumGrid[i][j] -= prefixSumGrid[i-1][j-1];
            }
        }
    }
    return prefixSumGrid;
}

int main()
{
    vector<vector<int>> grid = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    vector<vector<int>> result = prefixSum2D(grid);
    for(int i = 0 ; i < result.size() ; i++) {
        for(int j = 0 ; j < result[i].size() ; j++) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// 1 3 6 10 
// 6 14 24 36 
// 15 33 54 78 
// 28 60 96 136 