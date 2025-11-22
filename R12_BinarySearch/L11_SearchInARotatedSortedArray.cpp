
// Leetcode : 33

// Search in a Rotated Sorted Array :: Unique Elements

// sorted array
// {1,2,3,4,5,6,7,8,9}

// rotated at 7
// {0,1,2,3,4,5,6,7,8}
// {7,8,9,1,2,3,4,5,6}

#include <iostream>
#include <vector>
using namespace std;


// Linear Search : O(n)
int searchNaive(vector<int>& nums, int target) {
    int n = nums.size();

    for(int i = 0 ; i < n ; i++) {
        if(nums[i] == target) {
            return i;
        }
    }
    return -1;
}

// Binary Search :: Sorted Array & Searching Question
// T.C. = O(logn) 
// S.C. = O(1)
int search(vector<int>& nums, int target) {
    int n = nums.size();
    // logic is to identify the sorted part
    int lo = 0;
    int hi = n-1;

    while(lo <= hi) {
        int mid = lo + (hi-lo) / 2;

        if(nums[mid] == target) {
            return mid;
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

