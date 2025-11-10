// There is an array , you need find the minimum absolute difference between any two halves of a even length subarray of the array, meaning taking out a even length subarray than dividing it into two half left and right and than calculating the minimum absolute difference between them. Eg test case : if suppose array is [1,2,3,4,5] than all even length subarrays are [1,2], [2,3], [3,4], [4,5], [1,2,3,4], [2,3,4,5] so for [1,2] ans is | 1-2 | = 1 , for [2,3] the ans is |2-3| = 1 , for [3,4] the ans is |3-4| = 1, for [4,5] the ans is |4-5| = 1, for [1,2,3,4] = |(1+2) - (3+4)| = 4, for [2,3,4,5] = |(2+3) - (4+5)| = 4, so the minimum absolute difference will be 1, so return 1, in case the array doesn't have a even length subarray return -1. Write a code in c++ for the above problem. Also, discuss both brute force and optimised solution.

// 0 1
// 1 2
// mid = (i + j) / 2 = 0

// 0 1 2 3
// 1 2 3 4
// mid = (0 + 3) / 2  = 1


#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

// Brute Force
// T.C. = O(n^3)
// S.C. = O(1)
int minimumAbsoluteDifference_Naive(vector<int>& nums) {
    int n = nums.size();
    int minAbsDiff = INT_MAX;
    for(int i = 0 ; i < n ; i++) {  // O(n)
        for(int j = i ; j < n ; j++) {  // O(n)
            // checking for even length subarray
            if((j-i+1) % 2 == 0) {
                // split into two parts
                int pivot = (i+j) / 2;
                int leftSum = 0;
                int rightSum = 0;
                // O(n)
                for(int k = i ; k <= pivot ; k++) {
                    leftSum += nums[k];
                }
                for(int k = pivot+1 ; k <= j ; k++) {
                    rightSum += nums[k];
                }
                int absDiff = abs(leftSum - rightSum);
                minAbsDiff = min(minAbsDiff,absDiff);
            }
        }
    }
    return minAbsDiff == INT_MAX ? -1 : minAbsDiff;
}

// Optimised Solution : Prefix Sum
// T.C. = O(n^2)
// S.C. = O(n)
int minimumAbsoluteDifference(vector<int>& nums) {
    int n = nums.size();
    int minAbsDiff = INT_MAX;
    vector<int> prefixSum(n+1,0);
    prefixSum[0] = 0;
    // O(n+1)
    for(int i = 1 ; i < n+1 ; i++) {
        prefixSum[i] = prefixSum[i-1] + nums[i-1];
    }

    // for(int i = 0 ; i < n+1 ; i++) {
    //     cout<<prefixSum[i]<<" ";
    // }
    // 0 1 3 6 10 15 
    // cout<<endl;

    // [1,2,3,4, 5]
    // [0,1,3,6,10,15]
    // 2 : 1,2 & 2,3 & 3,4 & 4,5
    // 4 : 1,2,3,4 & 2,3,4,5
    // Iterate through all possible even-length subarrays
    for(int l = 2 ; l <= n ; l += 2) {
        // mid factor
        int h = l / 2;
        // how many subarrays of length 2 and 4 respectively
        for(int s = 0 ; s <= n - l ; s++) {
            int e = s + l;
            // Calculate left half sum
            int leftSum = prefixSum[s+h] - prefixSum[s];
            
            // Calculate right half sum  
            int rightSum = prefixSum[e] - prefixSum[s+h];
            
            int diff = abs(leftSum - rightSum);
            minAbsDiff = min(minAbsDiff, diff);
        }
    }
    return minAbsDiff == INT_MAX ? -1 : minAbsDiff;
}


int main()
{
    vector<int> nums = {1,2,3,4,5};
    cout<<minimumAbsoluteDifference_Naive(nums)<<endl; // 1
    vector<int> arr = {5};
    cout<<minimumAbsoluteDifference_Naive(arr)<<endl;  // -1
    cout<<minimumAbsoluteDifference(nums)<<endl; // 1
    cout<<minimumAbsoluteDifference(arr)<<endl;  // -1
    return 0;
}