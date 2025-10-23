// Leetcode : 2022
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    // Check if the conversion is possible
    if(original.size() != m*n) {
        return {};
    }
    // Initialize with proper dimensions
    vector<vector<int>> ans(m,vector<int>(n));
    int idx = 0;
    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            ans[i][j] = original[idx++];
        }
    }
    return ans;
}

int main()
{
    vector<int> original = {1,2,3,4};
    int m = 2;
    int n = 2;
    for(int i = 0 ; i < original.size() ; i++) {
        cout<<original[i]<<" ";
    }
    // 1 2 3 4 
    cout<<endl;

    vector<vector<int>> ans = construct2DArray(original,m,n);
    for(int i = 0 ; i < ans.size() ; i++) {
        for(int j = 0 ; j < ans[i].size() ; j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// 1 2 
// 3 4 