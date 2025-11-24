// Leetcode : 162

// nums[i-1] < nums[i] > nums[i+1]
// can have multiple peaks

#include <iostream>
#include <vector>
using namespace std;

// Brute Force 
// T.C. = O(n)
// S.C. = O(1)
int findPeakElementNaive(vector<int>& nums) {
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        // Check if it's a peak element
        if(i == 0) {
            // Only one element in array
            if(i == n-1) {
                return i; 
            // First element only needs to check right neighbor
            } 
            else {
                if(nums[i] > nums[i+1]) {
                    return i;
                }
            }
        } 
        else if(i == n-1) {
            // Last element only needs to check left neighbor
            if(nums[i] > nums[i-1]) {
                return i;
            }
        } 
        else {
            // Middle elements need to check both neighbors
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) {
                return i;
            }
        }
    }
    return -1;
}

// Binary Search
// T.C. = O(logn)
// S.C. = O(1)
// Works for single peak and multiple peaks both.
int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) {
        return 0;
    }
    if(nums[0] > nums[1]) {
        return 0;
    }
    if(nums[n-1] > nums[n-2]) {
        return n-1;
    }
    int lo = 1;
    int hi = n-2;
    while(lo <= hi) {
        int mid = lo + (hi-lo) / 2;
        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
            return mid;
        }
        // if mid lies in increasing phase
        else if(nums[mid] > nums[mid-1]) {
            lo = mid + 1;
        }
        // if mid lies in decreasing phase
        else if(nums[mid] > nums[mid+1]) {
            hi = mid - 1;
        }
        // Visualise using graph by taking single and multiple peaks examples for more clearity...
        else { // {1,5,1,2,1} :: see mid at 1
            // nums[mid] < nums[mid-1] && nums[mid] < nums[mid+1]
            // Both are allowed as we have peaks both sides
            lo = mid + 1;
            // hi = mid - 1;
        }
    }
    return -1;
}

// {10,11,12,13,9,8,7,6,5,4}
// {10,11,12,13}
// {12,13}
// {13}

int main()
{
    vector<int> nums = {10,11,12,13,9,8,7,6,5,4};
    cout<<findPeakElement(nums)<<endl; // 3
    vector<int> arr = {1,5,1,2,1};
    cout<<findPeakElement(arr)<<endl; // 1 or 3
    return 0;
}