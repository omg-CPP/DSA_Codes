#include <iostream>
#include <vector>
using namespace std;

// Given a matrix of size m X n with 0’s and 1’s, you enter the matrix at cell (0,0) in left to right direction. Whenever you encounter a 0 you retain it in the same direction, else if you encounter a 1 you have to change the direction to the right of the current direction and change that 1 value to 0, you have to find out from which index you will leave the matrix at the end.

//     n
// w       e
//     s

// i -> row
// j -> col

// east : e : i,j+1
// south : s : i+1,j
// west : w : i,j-1
// north : n : i-1,j

// east -> south -> west -> north
// 90 Degrees Dir

// dirn = 0 (east)
// dirn = 1 (south)
// dirn = 2 (west)
// dirn = 3 (north)
// dirn = 0 (east)

vector<int> FindExitPoint(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    // Initial Direction : east (left to right)
    int dirn = 0;
    // As you enter the matrix at cell (0,0) in left to right direction.
    int i = 0;
    int j = 0;
    // 0 - e && 1 - s && 2 - w && 3 - n && 4 - e
    while(true) {

        // This ensures if matrix[i][j] == 0 => Dirn will not change
        dirn = (dirn + matrix[i][j]) % 4;
        if(dirn == 0) { // east
            j++;
        }
        else if(dirn == 1) { // south
            i++;
        }
        else if(dirn == 2) { // west
            j--;
        }
        else if(dirn == 3) { // north
            i--;
        }

        // checking if exit point is acheived

        if(i < 0) {
            i++;
            break;
        }
        else if(i == m) {
            i--;
            break;
        }
        else if(j < 0) {
            j++;
            break;
        }
        else if(j == n) {
            j--;
            break;
        }
    }
    return {i,j};
}

int main()
{
    vector<vector<int>> matrix = {{0,1,0},{0,1,1},{0,0,0}};
    vector<int> exit = FindExitPoint(matrix);
    for(int i = 0 ; i < exit.size() ; i++) {
        cout<<exit[i]<<" ";
    }
    // 1 0 
    return 0;
}