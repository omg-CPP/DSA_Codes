// Distinct values in the array
// GFG : Find Kth Rotation

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// code to find the minimum element in a rotated sorted array
int timesArrayRotated(vector<int>& nums) {
    int n = nums.size();
    int ans = INT_MAX;
    int lo = 0;
    int hi = n-1;
    int index = -1;
    while(lo <= hi) {
        int mid = lo + (hi-lo) / 2;

        // slight optimisation
        // if the search space is already sorted
        // then nums[lo] will always be smallest
        // in that search space
        if(nums[lo] <= nums[hi]) {
            if(nums[lo] < ans) {
                index = lo;
                ans = nums[lo];
            }
            break;
        }

        // check if left half is sorted
        if(nums[lo] <= nums[mid]) {
            if(nums[lo] < ans) {
                index = lo;
                ans = nums[lo];
            }
            lo = mid + 1;
        }
        // check if right half is sorted
        else { // nums[mid] <= nums[hi]
            if(nums[mid] < ans) {
                index = mid;
                ans = nums[mid];
            }
            hi = mid - 1;
        }
    }
    return index;
}


int main()
{
    vector<int> nums = {7,6,5,1,2,3,4};
    vector<int> arr = {1,2,3,4,5,6,7};
    cout<<timesArrayRotated(nums)<<endl; // 3
    cout<<timesArrayRotated(arr)<<endl;  // 0
    return 0;
}