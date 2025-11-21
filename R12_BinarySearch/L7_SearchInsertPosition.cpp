#include <iostream>
#include <vector>
using namespace std;

// lower bound : arr[idx] >= x

// arr = {1,2,4,7} 
// x = 6
// x = 2

// similar to lower bound
int searchInsertPosition(vector<int>& nums, int x) {
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

    return 0;
}