
// arr = {10,20,30,40,50}

// floor :: larget no in array <= x
// ceil :: smallest no in array >= x :: lower bound

// x = 25
// floor :: 20
// ceil :: 30

#include <iostream>
#include <vector>
using namespace std;

int floor(vector<int>& nums, int x) {
    int n = nums.size();
    int lo = 0;
    int hi = n-1;
    int ans = -1;

    while(lo <= hi) {

        int mid = lo + (hi-lo) / 2;

        if(nums[mid] <= x) {
            ans = nums[mid];
            lo = mid + 1;
        }

        else { // nums[mid] > x
            hi = mid - 1;
        }
    }
    return ans;
}

int ceil(vector<int>& nums, int x) {
    int n = nums.size();
    int lo = 0;
    int hi = n-1;
    int ans = -1;

    while(lo <= hi) {

        int mid = lo + (hi-lo) / 2;
        
        if(nums[mid] >= x) {
            ans = nums[mid];
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
    vector<int> nums = {10,20,30,40,50};
    int x = 25;
    cout<<floor(nums,x)<<endl; // 20
    cout<<ceil(nums,x)<<endl; // 30
    return 0;
}
