// GFG

#include <iostream>
#include <vector>
using namespace std;

vector<int> prefixSum2D(vector<vector<int>>& grid, vector<vector<int>>& queries) {
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
    
    vector<int> result;
    for(auto& q : queries) {
        int r1 = q[0], c1 = q[1];
        int r2 = q[2], c2 = q[3];

        int total = prefixSumGrid[r2][c2];
        int top = (r1 > 0) ? prefixSumGrid[r1-1][c2] : 0;
        int left = (c1 > 0) ? prefixSumGrid[r2][c1-1] : 0;
        int overlap = (r1 > 0 && c1 > 0) ? prefixSumGrid[r1-1][c1-1] : 0;

        int sum = total - top - left + overlap;
        result.push_back(sum);
    }
    return result;
}

int main()
{
    vector<vector<int>> grid = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

    vector<vector<int>> queries = {{1,1,2,2}};

    vector<int> result = prefixSum2D(grid,queries);

    for(int& sum : result) {
        cout<<sum<< " ";
    }
    // 34 
    cout<<endl;
    return 0;
}