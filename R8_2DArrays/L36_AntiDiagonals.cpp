#include <iostream>
#include <vector>
using namespace std;
vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    int m = nums.size();
    int n = nums[0].size();
    vector<int> ans(m*n);
    int idx = 0;
    for(int k = 0 ; k <= n-1 ; k++) {
        int i = 0;
        int j = k;
        while(j >= 0) {
            ans[idx++] = nums[i][j];
            i++;
            j--;
        }
    }

    for(int k = 1 ; k <= m-1 ; k++) {
        int i = k;
        int j = n-1;
        while(i <= m-1) {
            ans[idx++] = nums[i][j];
            i++;
            j--;
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
    return 0;
}

// 1 2 3 
// 4 5 6 
// 7 8 9 

// Diagonal Traversal Pattern : 
// 1 2 4 3 5 7 6 8 9 