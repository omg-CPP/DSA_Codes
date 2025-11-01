#include <iostream>
#include <vector>
using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<int> ans(m*n);
    int row = 0;
    int col = 0;
    bool up = true;
    int idx = 0;
    while(row < m && col < n) {
        if(up == true) {
            while(row > 0 && col < n-1) {
                ans[idx++] = mat[row][col];
                row--;
                col++;
            }
            ans[idx++] = mat[row][col];
            if(col == n-1) {
                row++;
            }
            else {
                col++;
            }
        }
        else { // up == false => down
            while(row < m-1 && col > 0) {
                ans[idx++] = mat[row][col];
                row++;
                col--;
            }
            ans[idx++] = mat[row][col];
            if(row == m-1) {
                col++;
            }
            else {
                row++;
            }
        }
        up = !up;
    }
    return ans;
}

int main()
{
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    for(int i = 0 ; i < matrix.size() ; i++) {
        for(int j = 0 ; j < matrix[i].size() ; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    vector<int> ans = findDiagonalOrder(matrix);
    cout<<"Diagonal Traversal Pattern : "<<endl;
    for(int i = 0 ; i < ans.size() ; i++) {
        cout<<ans[i]<<" ";
    }

    cout<<endl<<endl;

    vector<vector<int>> mat = {{00,01,02,03,04,05},{10,11,12,13,14,15},{20,21,22,23,24,25},{30,31,32,33,34,35},{40,41,42,43,44,45},{50,51,52,53,54,55}};
    for(int i = 0 ; i < mat.size() ; i++) {
        for(int j = 0 ; j < mat[i].size() ; j++) {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    vector<int> res = findDiagonalOrder(mat);
    cout<<"Diagonal Traversal Pattern : "<<endl;
    for(int i = 0 ; i < res.size() ; i++) {
        cout<<res[i]<<" ";
    }
    return 0;
}

// 1 2 3 
// 4 5 6 
// 7 8 9 

// Diagonal Traversal Pattern : 
// 1 2 4 7 5 3 6 8 9 

// 0 1 2 3 4 5 
// 10 11 12 13 14 15 
// 20 21 22 23 24 25 
// 30 31 32 33 34 35 
// 40 41 42 43 44 45 
// 50 51 52 53 54 55 

// Diagonal Traversal Pattern : 
// 0 1 10 20 11 2 3 12 21 30 40 31 22 13 4 5 14 23 32 41 50 51 42 33 24 15 25 34 43 52 53 44 35 45 54 55