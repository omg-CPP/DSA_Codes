// Duplicates are present in the array

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// T.C. = O(logn)
// S.C. = O(1)
int timesArrayRotated(vector<int>& nums) {
    int n = nums.size();
    int ans = INT_MAX;
    int lo = 0;
    int hi = n-1;

    int idx = -1;

    while(lo <= hi) {
        int mid = lo + (hi-lo)/2;

        // If left boundary equals right boundary, handle duplicates
        // Handle duplicates at boundaries
        if(nums[lo] == nums[hi]) {
            if(nums[lo] < ans) {
                ans = nums[lo];
                idx = lo;
            }
            lo++;
            hi--;
            continue;
        }

        // slight optimisation
        // if the search space is already sorted
        // then nums[lo] will always be smallest
        // in that search space
        if(nums[lo] <= nums[hi]) {
            if(nums[lo] < ans) {
                ans = nums[lo];
                idx = lo;
            }
            break;
        }

        // check if left half is sorted
        if(nums[lo] <= nums[mid]) {
            if(nums[lo] < ans) {
                ans = nums[lo];
                idx = lo;
            }
            lo = mid + 1;
        }
        // check if right half is sorted
        else { // nums[mid] <= nums[hi]
            if(nums[mid] < ans) {
                ans = nums[mid];
                idx = mid;
            }
            hi = mid - 1;
        }
    }
    return idx;
}

int main()
{
    vector<int> nums = {3,3,4,4,5,1,2,3};
    cout<<timesArrayRotated(nums)<<endl; // 5
    return 0;
}
