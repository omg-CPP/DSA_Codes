// Leetcode : 2016

// Given a 0-indexed integer array nums of size n, find the maximum difference between nums[i] and nums[j] (i.e., nums[j] - nums[i]), such that 0 <= i < j < n and nums[i] < nums[j].

// Return the maximum difference. If no such i and j exists, return -1.

// maximum diff is maintained while changing the minSoFar
// 7 3 8 2 6 5


#include <iostream>
#include <vector>
using namespace std;

// T.C. = O(N)
// S.C. = O(1)
int maximumDifference(vector<int>& nums) {
    int n = nums.size();
    int maxDiff = -1;
    int minSoFar = nums[0];
    for(int i = 1 ; i < n ; i++) {
        if(nums[i] > minSoFar) {
            maxDiff = max(maxDiff, nums[i]-minSoFar);
        }
        minSoFar = min(minSoFar, nums[i]);
    }
    return maxDiff;
}


int main()
{
    vector<int> nums = {7,3,8,2,6,5};
    cout<<maximumDifference(nums)<<endl; // 5
    return 0;
}
