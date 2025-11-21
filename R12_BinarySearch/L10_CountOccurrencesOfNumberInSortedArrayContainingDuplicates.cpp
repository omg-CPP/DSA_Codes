// Number of Occurrences

#include <iostream>
#include <vector>
using namespace std;

int numberOfOccurrences(vector<int>& nums, int target) {
    int n = nums.size();
    int lo = 0;
    int hi = n-1;

    // first first occurrence
    int first = -1;
    while(lo <= hi) {
        int mid = lo + (hi-lo) / 2;
        if(nums[mid] == target) {
            first = mid;
            hi = mid-1;
        }
        else if(nums[mid] < target) {
            lo = mid + 1;
        }
        else { // nums[mid] > target
            hi = mid-1;
        }
    }

    if(first == -1) {
        // does not occur in the array
        return 0;
    }

    lo = 0;
    hi = n-1;

    // finding last occurrence
    int last = -1;
    while(lo <= hi) {
        int mid = lo + (hi-lo) / 2;
        if(nums[mid] == target) {
            last = mid;
            lo = mid + 1;
        }
        else if(nums[mid] < target) {
            lo = mid + 1;
        }
        else { // nums[mid] > target
            hi = mid-1;
        }
    }

    // is not a duplicate
    if(first == last) {
        return 1;
    }

    return (last - first + 1);
}

int main()
{
    vector<int> nums = {2,4,6,8,8,8,11,13};
    int target = 8;
    cout<<numberOfOccurrences(nums,target)<<endl; // 3

    vector<int> nums1 = {2,4,6,8,11,13};
    cout<<numberOfOccurrences(nums1,target)<<endl; // 1

    vector<int> nums2 = {2,4,6,11,13};
    cout<<numberOfOccurrences(nums2,target)<<endl; // 0
    return 0;
}