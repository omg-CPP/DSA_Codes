// Leetcode : 3197
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Time Complexity: O(m² × n² + m³ × n + m × n³)
// Space Complexity: O(1) (auxiliary space)

int minimumArea(int startRow, int endRow, int startCol, int endCol, vector<vector<int>>& grid) {
    int m = grid.size(); 
    int n = grid[0].size(); 

    int minRow = m; 
    int maxRow = -1;
    int minCol = n; 
    int maxCol = -1;
    bool foundOne = false;

    for(int i = startRow ; i < endRow ; i++) {
        for(int j = startCol ; j < endCol ; j++) {
            if(grid[i][j] == 1) {
                foundOne = true;
                minRow = min(minRow,i); 
                maxRow = max(maxRow,i); 

                minCol = min(minCol,j); 
                maxCol = max(maxCol,j); 
            }
        }
    }

    // If no '1's found in this region, return 0
    if (foundOne == false) {
        return 0;
    }

    int l = (maxCol - minCol + 1); 
    int b = (maxRow - minRow + 1); 

    int area = l*b; 
    return area;
}

int helper(vector<vector<int>>& grid) {
    int m = grid.size(); // no of rows
    int n = grid[0].size(); // no of columns

    int result = INT_MAX;

    // case 1 : T Shaped Split : Horizontal than Vertical : m² × n²
    for(int rowSplit = 1 ; rowSplit < m ; rowSplit++) {
        for(int colSplit = 1 ; colSplit < n ; colSplit++) {
            
            int top = minimumArea(0,rowSplit,0,n,grid);
            int bottomLeft = minimumArea(rowSplit,m,0,colSplit,grid);
            int bottomRight = minimumArea(rowSplit,m,colSplit,n,grid);

            if(top != 0 && bottomLeft != 0 && bottomRight != 0) {
                result = min(result, top + bottomLeft + bottomRight);
            }
        }
    }

    // case 2 : Reversed T shaped Split : Vertical than Horizontal : m² × n²
    for(int colSplit = 1 ; colSplit < n ; colSplit++) {
        for(int rowSplit = 1 ; rowSplit < m ; rowSplit++) {

            int topLeft = minimumArea(0,rowSplit,0,colSplit,grid);
            int topRight = minimumArea(0,rowSplit,colSplit,n,grid);
            int bottom = minimumArea(rowSplit,m,0,n,grid);

            if(topLeft != 0 && topRight != 0 && bottom != 0) {
                result = min(result, topLeft + topRight + bottom);
            }
        }
    }

    // case 3 : 3 horizontal splits : m³ × n : m² x (m x n)
    for(int split1 = 1 ; split1 < m ; split1++) {
        for(int split2 = split1+1 ; split2 < m ; split2++) {
            int top = minimumArea(0,split1,0,n,grid);
            int middle = minimumArea(split1,split2,0,n,grid);
            int bottom = minimumArea(split2,m,0,n,grid);

            if(top != 0 && middle != 0 && bottom != 0) {
                result = min(result, top + middle + bottom);
            }
        }
    }

    // case 4 : 3 vertical splits : m × n³ : n² x (m x n)
    for(int split1 = 1 ; split1 < n ; split1++) {
        for(int split2 = split1+1 ; split2 < n ; split2++) {
            int left = minimumArea(0,m,0,split1,grid);
            int middle = minimumArea(0,m,split1,split2,grid);
            int right = minimumArea(0,m,split2,n,grid);

            if(left != 0 && middle != 0 && right != 0) {
                result = min(result, left + middle + right);
            }
        }
    }
    return result;
}

int minimumSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> rotatedGrid(n,vector<int>(m));
    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            rotatedGrid[j][m-i-1] = grid[i][j];
        }
    }
    int res1 = helper(grid);
    int res2 = helper(rotatedGrid);
    return min(res1,res2);
}

int main()
{
    vector<vector<int>> grid = {{0,1,0,1},{0,1,0,0},{0,1,0,1}};
    int minSum = minimumSum(grid);
    cout<<minSum<<endl;
    return 0;
}