// Leetcode : 154
// Duplicates
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Brute Force 
// T.C. = O(n)
// S.C. = O(1)
int findMinNaive(vector<int>& nums) {
    int n = nums.size();
    int ans = INT_MAX;
    for(int i = 0 ; i < n ; i++) {
        ans = min(ans,nums[i]);
    }
    return ans;
}


// Binary Search
// T.C. = O(logn)
// S.C. = O(1)
int findMin(vector<int>& nums) {
    int n = nums.size();
    int ans = INT_MAX;
    int lo = 0;
    int hi = n-1;

    while(lo <= hi) {
        int mid = lo + (hi-lo)/2;

        // If left boundary equals right boundary, handle duplicates
        if(nums[lo] == nums[hi]) {
            ans = min(ans, nums[lo]);
            lo++;
            hi--;
            continue;
        }

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
    vector<int> nums = {2,2,2,0,1};
    cout<<findMinNaive(nums)<<endl; // 0
    cout<<findMin(nums)<<endl; // 0
    return 0;
}

// 4,1,2,3,4
// ans = 4
// 1,2,3
// ans = 1

// 2,2,2,0,1
// nums[mid] = 2
// left part is sorted
// ans = 2
// lo = 3, hi = 4
// mid = 3 :: nums[mid] = 0
// already sorted
// ans = nums[lo] = 0
// break out of loop and returns the ans