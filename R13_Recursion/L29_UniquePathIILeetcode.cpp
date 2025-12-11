#include <iostream>
#include <vector>
using namespace std;
// TLE : Has to be optimised with DP
int helper(int sr, int sc, int er, int ec, vector<vector<int>>& obstacleGrid) {
    // base cases
    if(sr > er || sc > ec) {
        return 0;
    }
    if(obstacleGrid[sr][sc] == 1) {
        return 0;
    }
    if(sr == er && sc == ec) {
        return 1;
    }
    // down
    int downWays = helper(sr+1,sc,er,ec,obstacleGrid);
    // right
    int rightWays = helper(sr,sc+1,er,ec,obstacleGrid);
    return downWays + rightWays;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    // Check if start or end position is blocked
    if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) {
        return 0;
    }
    int totalWays = helper(0,0,m-1,n-1,obstacleGrid);
    return totalWays;
}

int main()
{
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    int ways = uniquePathsWithObstacles(obstacleGrid);
    cout<<ways<<endl; // 2
    return 0;
}