
// Upper Bound : smallest Index such that arr[index] > x

// eg = {2,3,6,7,8,8,11,11,11,12}
// n = 10

// if x = 6 :: UB = 7 at index 3
// if x = 11 :: UB = 12 at index 9
// if x = 12 :: UB = 10 (size)
// if x = 0 :: UB = 2 at index 0

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Using Binary Search
// T.C. = O(log2(n))
// S.C. = O(1)
int upperBound(vector<int>& nums, int x) {
    int n = nums.size();
    int lo = 0;
    int hi = n-1;
    int ans = n;
    while(lo <= hi) {
        int mid = lo + (hi-lo) / 2;
        
        if(nums[mid] > x) {
            ans = mid;
            hi = mid - 1;
        }
        else { // nums[mid] <= x
            lo = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {2,3,6,7,8,8,11,11,11,12};
    int x = 11;
    cout<<upperBound(nums,x)<<endl; // 9
    // C++ STL
    int up = upper_bound(nums.begin(),nums.end(),x)-nums.begin();
    cout<<up<<endl; // 9
    return 0;
}