#include <iostream>
#include <vector>
using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    int m = nums.size();
    int n = nums[0].size();
    vector<int> ans(m*n);
    int idx = 0;
    for(int k = 0 ; k <= m-1 ; k++) {
        int i = k;
        int j = 0;
        while(i >= 0) {
            ans[idx++] = nums[i][j];
            i--;
            j++;
        }
    }

    for(int k = 1 ; k <= n-1 ; k++) {
        int i = m-1;
        int j = k;
        while(j <= n-1) {
            ans[idx++] = nums[i][j];
            i--;
            j++;
        }
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

    cout<<endl<<endl;

    // Error in Leetcode
    
    // vector<vector<int>> arr = {{1,2,3,4,5},{6,7},{8},{9,10,11},{12,13,14,15,16}};
    // for(int i = 0 ; i < arr.size() ; i++) {
    //     for(int j = 0 ; j < arr[i].size() ; j++) {
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    // vector<int> sol = findDiagonalOrder(arr);
    // cout<<"Diagonal Traversal Pattern : "<<endl;
    // for(int i = 0 ; i < sol.size() ; i++) {
    //     cout<<sol[i]<<" ";
    // }

    // 1 2 3 4 5 
    // 6 7 
    // 8 
    // 9 10 11 
    // 12 13 14 15 16 

    return 0;
}

// 1 2 3 
// 4 5 6 
// 7 8 9 

// Diagonal Traversal Pattern : 
// 1 4 2 7 5 3 8 6 9 

// 0 1 2 3 4 5 
// 10 11 12 13 14 15 
// 20 21 22 23 24 25 
// 30 31 32 33 34 35 
// 40 41 42 43 44 45 
// 50 51 52 53 54 55 

// Diagonal Traversal Pattern : 
// 0 10 1 20 11 2 30 21 12 3 40 31 22 13 4 50 41 32 23 14 5 51 42 33 24 15 52 43 34 25 53 44 35 54 45 55 