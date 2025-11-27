// GFG
// Median in rowwise sorted matrix
// Given a row-wise sorted matrix mat[][] of size n*m, where the number of rows and columns is always odd. Return the median of the matrix.
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// To find the median of a set of numbers, first arrange the numbers in ascending order.

// median : if n = odd => median = [(n+1)/2]th term
// eg : 1 2 3 4 5 6 7
// median = [(7+1)/2]th term = 4th term = 4

// // median : if n = even => 
// median = {[n/2]th term + [(n/2) + 1]th term} / 2
// eg : 1 2 3 4 5 6 7 8 9 10
// median = {[10/2]th term + [(10/2) + 1]th term } / 2
// = {5th term + 6th term} / 2 = {5 + 6} / 2 
// = 11 / 2 = 5.5

// Brute Force : (m*n) + [(m*n)*log(m*n)]
int medianNaive(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<int> list;
    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            list.push_back(mat[i][j]);
        }
    }
    for(int i = 0 ; i < list.size() ; i++) {
        cout<<list[i]<<" ";
    }
    cout<<endl;
    sort(list.begin(),list.end());
    return list[(m*n)/2];
}


// Upper Bound : smallest Index such that arr[index] > x
// index(idx) :: 0 1 2 3 4 5 6
// elements   :: 1 2 3 4 5 6 7 
// x = 5 
// lo = 0 && hi = 6
// mid = 4
// lo = 5 && hi = 6
// mid = 5
// ans = 5
// hi = mid - 1 = 4
// lo = 5 && hi = 4
// loop terminates
// return ans = 5
// O(logn)
int upperBound(vector<int>& nums, int x) {
    int n = nums.size();
    int lo = 0;
    int hi = n-1;
    int ans = n;
    while(lo <= hi) {
        int mid = lo + (hi-lo) / 2;
        
        if(nums[mid] > x) {
            ans = mid;
            hi = mid - 1;
        }
        else { // nums[mid] <= x
            lo = mid + 1;
        }
    }
    return ans;
}

// O(m * log2(n))
int countSmallEqual(vector<vector<int>>& mat, int x) {
    int m = mat.size();
    int n = mat[0].size();
    int cnt = 0; 
    // how many elements are less than equal to x
    for(int i = 0 ; i < m ; i++) {
        cnt += upperBound(mat[i],x);
    }
    return cnt;
}

// Optimal Approach : Binary Search
// 1 ≤ mat[i][j] ≤ 10^9
// T.C. = O((log2(10^9)) * (m * log2(n)))
// S.C. = O(1)
int median(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    int lo = INT_MAX;
    int hi = INT_MIN;
    for(int i = 0 ; i < m ; i++) {
        lo = min(lo,mat[i][0]);
        hi = max(hi,mat[i][n-1]);
    }

    int req = (m * n) / 2;  // 7
    while(lo <= hi) {
        int mid = lo + (hi - lo) /2;
        int smallEqual = countSmallEqual(mat,mid);
        if(smallEqual <= req) {
            lo = mid + 1;
        }
        else { // smallEqual > req
            hi = mid - 1;
        }
    }
    return lo;
}

int main()
{
    vector<vector<int>> mat = {{1,3,5},
                                {2,6,9},
                                {3,6,9}};
    cout<<medianNaive(mat)<<endl; // 5
    cout<<median(mat)<<endl; // 5
    return 0;
}

// 1  5  7  9 11
// 2  3  4  5 10
// 9 10 12 14 16 

// lo = 1
// hi = 16

// 1 2 3 4 5 7 9 9 10 10 11 12 13 14 15
// median = 9
// no of elements <= median(9) > 7

// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
// 1 2 3 4 4 6 6 7 9 11 12 13 13 14 14 15 :: count <= num

// lo = 1 && hi = 16
// mid = 8
// lo = mid + 1 = 9
// lo = 9 && hi = 16
// mid = 12
// hi = mid - 1 = 11
// lo = 9 && hi = 11
// mid = 10
// hi = mid - 1 = 9
// lo = 9 && hi = 9
// mid = 9
// hi = mid - 1 = 8
// lo = 9 && hi = 9
// loop terminates
// return lo = 9
