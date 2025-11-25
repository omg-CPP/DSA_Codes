// Leetcode : 1901

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Brute Force
// find largest element in the matrix , O(m*n)

int maxElement(vector<vector<int>>& mat, int mid) {
    int m = mat.size();
    int n = mat[0].size();
    int ans = INT_MIN;
    int row = -1;
    for(int i = 0 ; i < m ; i++) {
        if(mat[i][mid] > ans) {
            ans = mat[i][mid];
            row = i;
        }
    }
    return row;
}

// T.C. = O(log2(n) * m)
// S.C. = O(1)
vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    int lo = 0;
    int hi = n-1;
    while(lo <= hi) {
        int mid = lo + (hi-lo) / 2;
        int row = maxElement(mat,mid);
        int left = (mid-1) >= 0 ? mat[row][mid-1] : -1;
        int right = (mid+1) < n ? mat[row][mid+1] : -1;

        if(mat[row][mid] > left && mat[row][mid] > right) {
            return {row,mid};
        }
        else if(mat[row][mid] < right) {
            lo = mid + 1;
        }
        else if(mat[row][mid] < left) {
            hi = mid - 1;
        }
    }
    return {-1,-1};
}

int main() {
    vector<vector<int>> mat = {{4,2,5,1,4,5},{2,9,3,2,3,2},{1,7,6,0,1,3},{3,6,2,3,7,2}};
    vector<int> ans = findPeakGrid(mat);
    for(int i = 0 ; i < ans.size() ; i++) {
        cout<<ans[i]<<" ";
    } // 0 0
    cout<<endl;

    vector<vector<int>> arr = {{1,2,4},{2,5,3},{1,3,9}};
    vector<int> res = findPeakGrid(arr);
    for(int i = 0 ; i < res.size() ; i++) {
        cout<<res[i]<<" ";
    } // 1 1
    cout<<endl;
    return 0;
}

// 4 2 5 1 4 5
// 2 9 3 2 3 2
// 1 7 6 0 1 3
// 3 6 2 3 7 2

// -1 -1 -1 -1 -1 
// -1 10 20 15 -1
// -1 21 30 14 -1
// -1  7 16 32 -1
// -1 -1 -1 -1 -1 


// 1 2 4
// 2 5 3
// 1 3 9