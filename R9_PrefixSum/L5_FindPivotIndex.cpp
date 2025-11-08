#include <iostream>
#include <vector>
using namespace std;
// Leetcode : 724

// Given an array of integers nums, calculate the pivot index of this array.

// The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

// If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

// Return the leftmost pivot index. If no such index exists, return -1.

int pivotIndex(vector<int>& nums) {
    int n = nums.size();
    // creating prefix sum array
    for(int i = 1 ; i < n ; i++) {
        nums[i] = nums[i-1] + nums[i];
    }
    // now check for index
    // 0 to (i-1)th index tak ka sum == (i+1)th to n-1 index tak ka sum
    // in between lies ith index
    int leftSum;
    int rightSum;
    for(int i = 0 ; i < n ; i++) {
        if(i == 0) {
            leftSum = 0;
        }
        else {
            leftSum = nums[i-1];
        }
        if(i == n-1) {
            rightSum = 0;
        }
        else {
            rightSum = nums[n-1] - nums[i];
        }
        if(leftSum == rightSum) {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {1,7,3,6,5,6};
    for(int i = 0 ; i < nums.size() ; i++) {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    int idx = pivotIndex(nums);
    cout<<idx<<" is the index where the sum of all the numbers strictly to the left of it is equal to the sum of all the numbers strictly to it's right"<<endl;
    return 0;
}

// 1 7 3 6 5 6 
// 3 is the index where the sum of all the numbers strictly to the left of it is equal to the sum of all the numbers strictly to it's right