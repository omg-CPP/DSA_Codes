// Leetcode : 53

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Brute force : O(n^3)
// generate all possible sub-arrays 
// compute sum in a maxSum variable for each subarray
int maxSubArrayBruteForce(vector<int>& nums) {
    int n = nums.size();
    int maxSum = INT_MIN;
    for(int i = 0 ; i < n ; i++) {
        for(int j = i ; j < n ; j++) {
            int sum = 0;
            for(int k = i ; k <= j ; k++) {
                sum += nums[k];
            }
            maxSum = max(maxSum,sum);
        }
    }
    return maxSum;
}

// Better Approach : O(n^2)
int maxSubArrayBetter(vector<int>& nums) {
    int n = nums.size();
    int maxSum = INT_MIN;
    for(int i = 0 ; i < n ; i++) {
        int sum = 0;
        for(int j = i ; j < n ; j++) {
            sum += nums[j];
            maxSum = max(maxSum,sum);
        }
    }
    return maxSum;
}

// Optimal Approach : O(n)
// Kadane's Algorithm
// pos + pos = pos (value increases)
// neg + pos = pos (value increases)
// neg + neg = neg (value decreases)
// pos + neg = neg (value decreases)
int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    int maxSum = INT_MIN;
    for(int i = 0 ; i < n ; i++) {
        sum += nums[i];
        maxSum = max(maxSum,sum);
        if(sum < 0) {
            sum = 0;
        }
    }
    return maxSum;
}

// [3,-4,5,4,-1,7,-8] :: ans = 5 + 4 + -1 + 7 = 15
// [-1,-2,-3,-4,-5] :: ans = -1



int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArrayBruteForce(nums)<<endl; // 6
    cout<<maxSubArrayBetter(nums)<<endl; // 6
    cout<<maxSubArray(nums)<<endl; // 6
    return 0;
}