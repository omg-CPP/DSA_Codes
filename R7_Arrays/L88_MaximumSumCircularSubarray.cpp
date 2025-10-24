// Leetcode : 918

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
using namespace std;


// T.L.E : Time Limit Exceeded
// T.C. = O(n^2)

// Kadane's Algo to find maxSum in a Subarray
// O(n) Time
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

void reverseArray(vector<int>& nums, int i, int j) {
    while(i < j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        i++;
        j--;
    }
}

void rotateArray(vector<int>& nums) {
    int n = nums.size();
    reverseArray(nums,0,n-2);
    reverseArray(nums,0,n-1);
}

// Pre-requisite : Kandane's Algorithm
int maxSubarraySumCircularNaive(vector<int>& nums) {
    int n = nums.size();
    int maxSum = INT_MIN;
    for(int i = 0 ; i < n ; i++) {
        rotateArray(nums);
        int sum = maxSubArray(nums);
        maxSum = max(maxSum,sum);
    }
    return maxSum;
}

// Kadane's Algorithm
// 1,-2,3 :: minSum = -2
// -1,-1,-1 :: minSum = -3
int minSubarraySum(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    int minSum = INT_MAX;
    for(int i = 0 ; i < n ; i++) {
        sum += nums[i];
        minSum = min(minSum,sum);
        if(sum > 0) {
            sum = 0;
        }
    }
    return minSum;
}

int maxSubarraySumCircular(vector<int>& nums) {
    int n = nums.size();
    int totalSum = accumulate(nums.begin(),nums.end(),0);
    int minSum = minSubarraySum(nums);
    int maxSum = maxSubArray(nums); // case 1
    
    // totalSum = circularSum + minSum;
    // Proof by Contradiction
    int circularSum = totalSum - minSum; // case 2

    if(maxSum > 0) {
        return max(maxSum,circularSum);
    }
    else { // [-1,-1,-1]
        // maxSum = -1
        // minSum = -3
        // circularSum = -3 - (-3) = 0
        return maxSum;
    }
}

int main()
{
    vector<int> nums = {5,-3,5};
    cout<<maxSubarraySumCircularNaive(nums)<<endl; // 10
    return 0;
}

// rotating by 1 step
// {1,2,3,4}
// {3,2,1,4} :: reversing first n-1 elements
// {4,1,2,3} :: reversing complete array

// {4,1,2,3}
// {3,4,1,2}
// {2,3,4,1}


// Dry Run
// {1,-2,3} :: n = 3
// i = 0 :: {3,1,-2} : sum = 4
// i = 1 :: {-2,3,1} : sum = 4
// i = 2 :: {1,-2,3} : sum = 3