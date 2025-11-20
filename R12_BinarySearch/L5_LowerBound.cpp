// Lower Bound : smallest Index such that arr[index] >= x

// eg = [3,5,8,15,19]
// n = 5

// if x = 8 :: LB = 8 at index 2
// if x = 9 :: LB = 15 at index 3
// if x = 16 :: LB = 16 at index 4
// if x = 20 :: LB = n = 5 (size)


#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// T.C. = O(n)
// S.C. = O(1)
int lowerBoundNaive(vector<int>& nums, int x) {
    int n = nums.size();
    int idx = n;
    for(int i = 0 ; i < n ; i++) {
        if(nums[i] >= x) {
            idx = i;
            break;
        }
    }
    return idx;
}

// Using Binary Search
// T.C. = O(log2(n))
// S.C. = O(1)
int lowerBound(vector<int>& nums, int x) {
    int n = nums.size();
    int lo = 0;
    int hi = n-1;
    int ans = n;
    while(lo <= hi) {
        int mid = lo + (hi-lo) / 2;
        
        if(nums[mid] >= x) {
            ans = mid;
            hi = mid - 1;
        }
        else { // nums[mid] < x
            lo = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {3,5,8,15,19};
    cout<<lowerBoundNaive(nums,8)<<endl; // 2
    cout<<lowerBoundNaive(nums,9)<<endl; // 3
    cout<<lowerBoundNaive(nums,16)<<endl; // 4
    cout<<lowerBoundNaive(nums,20)<<endl; // 5

    cout<<lowerBound(nums,8)<<endl;  // 2
    cout<<lowerBound(nums,9)<<endl;  // 3
    cout<<lowerBound(nums,16)<<endl; // 4
    cout<<lowerBound(nums,20)<<endl; // 5

    int x = 9;
    int lb = lower_bound(nums.begin(),nums.end(),x) - nums.begin();
    cout<<lb<<endl; // 3
    return 0;
}