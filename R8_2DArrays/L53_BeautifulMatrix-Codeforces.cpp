// Codeforces : 263A - Beautiful Matrix
#include <iostream>
#include <vector>
using namespace std;

int beautifulMatrix(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int r,c;
    for(int i = 0 ; i < rows ; i++) {
        for(int j = 0 ; j < cols ; j++) {
            if(matrix[i][j] == 1) {
                r = i;
                c = j;
            }
        }
    }
    cout<<r<<" "<<c<<endl;  // for debugging purpose only => 1 4
    int ans = abs(2-r) + abs(2-c); // To bring 1 at row 2 and column 2 i.e. at the center of the matrix
    return ans;
}
int main()
{
    vector<vector<int>> matrix = {{0,0,0,0,0},{0,0,0,0,1},{0,0,0,0,0},
                                    {0,0,0,0,0},{0,0,0,0,0}};
    cout<<beautifulMatrix(matrix)<<endl; // 3
    return 0;
}

// 0 0 0 0 0 
// 0 0 0 0 1
// 0 0 0 0 0
// 0 0 0 0 0 
// 0 0 0 0 0