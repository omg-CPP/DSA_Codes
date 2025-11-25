// Leetcode : 2643
// Row with Maximum Ones

#include <iostream>
#include <vector>
using namespace std;

// Binary matrix 0/1
// return row with max ones

// T.C. = O(m*n)
// S.C. = O(1)
// works both in case of sorted and un-sorted rows
vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<int> ans(2,0);
    int idx = -1;
    int maxCount = -1;
    for(int i = 0 ; i < m ; i++) {
        int rowCount = 0;
        for(int j = 0 ; j < n ; j++) {
            rowCount += mat[i][j];
        }
        if(rowCount > maxCount) {
            maxCount =  rowCount;
            idx = i;
        }
    }
    ans[0] = idx;
    ans[1] = maxCount;
    return ans;
}

// GFG : Row with max 1's
// Binary Search for sorted rows only
// smallest index such that nums[i] >= x
int lowerBound(vector<int>& nums, int x) {
    int n = nums.size();
    int lo = 0;
    int hi = n-1;
    int ans = n;
    while(lo <= hi) {
        int mid = lo + (hi-lo) / 2;
        
        if(nums[mid] >= x) {
            ans = mid;
            hi = mid - 1;
        }
        else { // nums[mid] < x
            lo = mid + 1;
        }
    }
    return ans;
}

// lowerBound(1)
// upperBound(0)
// firstOccurrence(1)
// T.C. = O(m * log2(n))
// S.C. = O(1)
int rowWithMax1s(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    int idx = -1;
    int maxCount = 0;
    for(int i = 0 ; i < m ; i++) {
        int OnesCount = n - lowerBound(mat[i],1);
        if(OnesCount > maxCount) {
            idx = i;
            maxCount = OnesCount;
        }
    }
    return idx;
}

int main()
{
    vector<vector<int>> mat = {{0,0,1,1,1},
                                {0,0,0,0,0},
                                {0,1,1,1,1},
                                {0,0,0,0,0},
                                {0,0,1,1,1}};
    vector<int> ans = rowAndMaximumOnes(mat);
    for(int i = 0 ; i < ans.size() ; i++) {
        cout<<ans[i]<<" ";
    }
    // 2,4 :: row index 2 with 4 ones
    cout<<endl;

    vector<vector<int>> arr = {{0,0},{0,0}};

    cout<<rowWithMax1s(mat)<<endl; // 2
    cout<<rowWithMax1s(arr)<<endl; // -1
    return 0;
}
