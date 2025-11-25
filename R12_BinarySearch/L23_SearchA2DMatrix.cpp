// Leetcode : 74
// Sorted Matrix

#include <iostream>
#include <vector>
using namespace std;

// Brute Force
// T.C. = O(m*n)
// S.C. = O(1)
bool searchMatrixNaive(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            if(matrix[i][j] == target) {
                return true;
            }
        }
    }
    return false;
}

// O(logn)
bool binarySearch(vector<int>& nums, int target) {
    int n = nums.size();
    int lo = 0;
    int hi = n-1;
    while(lo <= hi) {
        int mid = lo + (hi-lo) / 2;
        if(nums[mid] == target) {
            return true;
        }
        else if(nums[mid] < target) {
            lo = mid + 1;
        }
        else { // nums[mid] > target
            hi = mid - 1;
        }
    }
    return false;
}

// T.C. = O(m + log2(n))
// Binary Search happens only in one row
// S.C. = O(1)
bool searchMatrixBetter(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    for(int i = 0 ; i < m ; i++) {
        if(matrix[i][0] <= target && target <= matrix[i][n-1]) {
            if(binarySearch(matrix[i],target)) {
                return true;
            }
            else {
                return false;
            }
        }
    }
    return false;
}

// Flatten a 2D array into 1D array :: just think in brain
// T.C. = O(log2(m*n))
// S.C. = O(1)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int lo = 0;
    int hi = m*n-1;
    while(lo <= hi) {
        int mid = lo + (hi-lo) / 2;
        // For intuition see a example by writing 1D indices
        int row = mid / n;
        int col = mid % n;
        if(matrix[row][col] == target) {
            return true;
        }
        else if(matrix[row][col] < target) {
            lo = mid + 1;
        }
        else { // matrix[row][col] > target
            hi = mid - 1;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},
                                {23,30,34,60}};
    int target = 3;
    cout<<searchMatrixNaive(matrix,target)<<endl; // 1
    cout<<searchMatrixBetter(matrix,target)<<endl; // 1
    cout<<searchMatrix(matrix,target)<<endl; // 1
    return 0;
}
