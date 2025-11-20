
#include <iostream>
#include <vector>
using namespace std;

// Recursive Binary Search

int recursiveBinarySearch(vector<int>& nums, int lo, int hi, int target) {
    // base case
    if(lo > hi) {
        return -1;
    }

    int mid = lo + (hi - lo) / 2;

    if(nums[mid] == target) {
        return mid;
    }

    else if(nums[mid] < target) { // search space is right side
        // call recursive binary search function 
        return recursiveBinarySearch(nums,mid+1,hi,target);
    }

    else { // nums[mid] > target :: search space is left side
        return recursiveBinarySearch(nums,lo,mid-1,target);
    }
}

int main() {
    vector<int> nums = {3,4,6,7,9,12,16,17};
    int target = 12;
    int n = nums.size();
    int lo = 0;
    int hi = n-1;
    int idx = recursiveBinarySearch(nums,lo,hi,target);
    if(idx == -1) {
        cout<<"Element not found"<<endl;
    }
    else {
        cout<<target<<" found at index : "<<idx<<endl;
    }
    return 0;
}

// 12 found at index : 5
// 11 :: Element not found
