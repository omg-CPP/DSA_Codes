
// Leetcode : 81

// Search in a Rotated Sorted Array II:: Duplicate can be there


// rotated at 7
// {0,1,2,3,4,5,6,7,8,9}
// {7,8,1,2,3,3,3,4,5,6}


// failing case :: 
//      {0,1,2,3,4,5,6}
// eg = {3,1,2,3,3,3,3}
// difficulty in finding the sorted and unsorted part
// so we shrink the array from both sides.
// =>     {1,2,3,3,3}

// {1,2,3,3,1,2,3}

// worst case : can be O(n/2)

#include <iostream>
#include <vector>
using namespace std;


// Linear Search : O(n)
bool searchNaive(vector<int>& nums, int target) {
    int n = nums.size();

    for(int i = 0 ; i < n ; i++) {
        if(nums[i] == target) {
            return true;
        }
    }
    return false;
}

// Binary Search :: Sorted Array & Searching Question
// T.C. = O(logn) 
// S.C. = O(1)

// Identifying the Sorted Half
bool search(vector<int>& nums, int target) {

    int n = nums.size();
    // logic is to identify the sorted part
    int lo = 0;
    int hi = n-1;

    while(lo <= hi) {
        int mid = lo + (hi-lo) / 2;

        if(nums[mid] == target) {
            return mid;
        }
        // stopping me to identify the sorted part
        if(nums[lo] == nums[mid] && nums[mid] == nums[hi]) {
            lo = lo + 1;
            hi = hi - 1;
            continue;
        }

        // if left part is sorted
        if(nums[lo] <= nums[mid]) {
            // checking if x is present in left part
            if(nums[lo] <= target && target <= nums[mid]) {
                hi = mid - 1;
            }
            // if x is present in right unsorted part
            else {
                lo = mid + 1;
            }
        }
        // if the right part is sorted
        else { // nums[mid] <= nums[hi]
            // checking if x is present in right part
            if(nums[mid] <= target && target <= nums[hi]) {
                lo = mid + 1;
            }
            // if x is present in left unsorted part
            else {
                hi = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {7,8,9,1,2,3,4,5,6};
    int target = 1;
    cout<<searchNaive(nums,target)<<endl; // 3
    cout<<search(nums,target)<<endl; // 3
    return 0;
}


// [1,1,1,1,1,1,1,1,1,13,1,1,1,1,1,1,1,1,1,1,1,1]
// target = 13
// arr = {13,1,1,1}
// again unsorted array and sorted array