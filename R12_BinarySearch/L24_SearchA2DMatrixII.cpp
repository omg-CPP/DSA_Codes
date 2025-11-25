// Leetcode : 240
// every row is sorted but the matrix entirely is not sorted

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

// T.C. = O(m * log2(n))
// Binary Search happens in each row
// S.C. = O(1)
bool searchMatrixBetter(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    for(int i = 0 ; i < m ; i++) {
        if(matrix[i][0] <= target && target <= matrix[i][n-1]) {
            if(binarySearch(matrix[i],target)) {
                return true;
            }
        }
    }
    return false;
}

// max no of operations = (m-1 + n-1) = (m+n-2)
// T.C. = O(m+n)
// S.C. = O(1)
// Concept of Elimination is followed
// starting from top-right corner
bool searchMatrix1(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int i = 0;
    int j = n-1;
    while(j >= 0 && i < m) {
        if(matrix[i][j] == target) {
            return true;
        }
        else if(matrix[i][j] < target) {
            i++;
        }
        else { // matrix[i][j] > target
            j--;
        }
    }
    return false;
}

// starting from bottom-left corner
bool searchMatrix2(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int i = m-1;
    int j = 0;
    while(i >= 0 && j < n) {
        if(matrix[i][j] == target) {
            return true;
        }
        else if(matrix[i][j] < target) {
            j++;
        }
        else { // matrix[i][j] > target
            i--;
        }
    }
    return false;
}

int main() {
    return 0;
}


