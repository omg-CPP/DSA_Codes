// Leetcode : 153 
// Unique Elements

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// nums = [0,1,2,4,5,6,7] might become:

// [4,5,6,7,0,1,2] if it was rotated 4 times.
// [0,1,2,4,5,6,7] if it was rotated 7 times.

// Naive Approach : O(n) Time
int findMinNaive(vector<int>& nums) {
    int n = nums.size();
    int minNum = INT_MAX;
    for(int i = 0 ; i < n ; i++) {
        minNum = min(minNum,nums[i]);
    }
    return minNum;
}

// For Unique Elements
// Binary Search : O(logn)
// sorted half may or may not have the answer
int findMin(vector<int>& nums) {
    int n = nums.size();
    int ans = INT_MAX;
    int lo = 0;
    int hi = n-1;
    while(lo <= hi) {
        int mid = lo + (hi-lo) / 2;

        // slight optimisation
        // if the search space is already sorted
        // then nums[lo] will always be smallest
        // in that search space
        if(nums[lo] <= nums[hi]) {
            ans = min(ans,nums[lo]);
            break;
        }

        // check if left half is sorted
        if(nums[lo] <= nums[mid]) {
            ans = min(ans,nums[lo]);
            lo = mid + 1;
        }
        // check if right half is sorted
        else { // nums[mid] <= nums[hi]
            ans = min(ans,nums[mid]);
            hi = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {4,5,6,7,0,1,2};
    cout<<findMinNaive(nums)<<endl; // 0
    cout<<findMin(nums)<<endl; // 0
    return 0;
}