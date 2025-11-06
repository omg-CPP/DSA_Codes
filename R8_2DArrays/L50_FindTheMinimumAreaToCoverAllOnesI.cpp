// Leetcode : 3195
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// T.C. = O(m*n)
// S.C. = O(1)
int minimumArea(vector<vector<int>>& grid) {
    int m = grid.size(); // 2
    int n = grid[0].size(); // 3

    int minRow = m; // 2
    int maxRow = -1;
    int minCol = n; // 3
    int maxCol = -1;

    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            if(grid[i][j] == 1) {
                minRow = min(minRow,i); // 0
                maxRow = max(maxRow,i); // 1

                minCol = min(minCol,j); // 0
                maxCol = max(maxCol,j); // 2
            }
        }
    }

    int l = (maxCol - minCol + 1); // 2 - 0 + 1 = 3
    int b = (maxRow - minRow + 1); // 1 - 0 + 1 = 2

    int area = l*b; // 3*2 = 6
    return area;
}

int main()
{
    vector<vector<int>> grid = {{0,1,0},{1,0,1}};
    int area = minimumArea(grid);
    cout<<area<<endl; // 6
    return 0;
}