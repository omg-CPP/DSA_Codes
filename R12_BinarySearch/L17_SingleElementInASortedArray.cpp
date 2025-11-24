// Leetcode : 540

#include <iostream>
#include <vector>
using namespace std;

// All the elements will be appearing twice except for one element.
// Naive Approach
// T.C. = O(n)
// S.C. = O(1)
int singleNonDuplicateNaive(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) {
        return nums[0];
    }
    for(int i = 0 ; i < n ; i++) {
        if(i == 0) {
            if(nums[i] != nums[i+1]) {
                return nums[i];
            }
        }
        else if(i == n-1) {
            if(nums[i] != nums[i-1]) {
                return nums[i];
            }
        }
        else { // All elements in the middle
            if(nums[i] != nums[i-1] && nums[i] != nums[i+1]) {
                return nums[i];
            }
        }
    }
    return 0; // general statement
}

// idx  : {0,1,2,3,4,5,6,7,8,9,10}
// nums = {1,1,2,2,3,3,4,5,5,6,6}
// even,odd :: left half
// odd,even :: right half
// T.C. = O(logn)
// S.C. = O(1)
int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) {
        return nums[0];
    }
    // trim down search space by one from left and right
    // seperately checking them
    if(nums[0] != nums[1]) {
        return nums[0];
    }
    if(nums[n-1] != nums[n-2]) {
        return nums[n-1];
    }
    // eliminate that part where element is not there
    int lo = 1;
    int hi = n-2;
    while(lo <= hi) {
        int mid = lo + (hi-lo) / 2;
        if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) {
            return nums[mid];
        }
        if((mid % 2 != 0 && nums[mid-1] == nums[mid]) || (mid % 2 == 0 && nums[mid] == nums[mid+1])) {
            // standing on left half
            // element is on the right half
            // eliminate left half
            lo = mid + 1;
        }
        else { // in all other cases 
            // shrink the right half
            hi = mid - 1;
        }
    }
    return -1; // dummy statement :: will never execute
}

int main()
{
    vector<int> nums = {1,1,2,3,3,4,4,8,8};
    cout<<singleNonDuplicateNaive(nums)<<endl; // 2
    return 0;
}