// Leetcode : 704

#include <iostream>
#include <vector>
using namespace std;

// T.C. = O(n)
// S.C. = O(1)

int search(vector<int>& nums, int target) {
    int n = nums.size();
    int lo = 0;
    int hi = n-1;
    while(lo <= hi) {
        // int mid = (lo + hi) / 2;
        int mid = lo + (hi - lo) / 2;
        if(nums[mid] == target) {
            return mid;
        }
        else if(nums[mid] < target) {
            lo = mid + 1;
        }
        else { // mums[mid] > target
            hi = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    cout<<search(nums,target)<<endl; // 4
    return 0;
}
