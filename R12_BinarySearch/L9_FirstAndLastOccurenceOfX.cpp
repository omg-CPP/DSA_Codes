
// Leetcode : 34

// {2,4,6,8,8,8,11,13}
// x = 8 :: FO = 3 & LO = 5
// x = 10 :: FO = -1 & LO = -1
// x = 11 :: FO = 6 & LO = 6

#include <iostream>
#include <vector>
using namespace std;


// T.C. = O(n)
// S.C. = O(1)
vector<int> searchRangeNaive(vector<int>& nums, int target) {
    int n = nums.size();
    int f = -1;
    int l = -1;
    for(int i = 0 ; i < n ; i++) {
        if(nums[i] == target) {
            // appearing first time
            if(f == -1) {
                f = i;
            }
            l = i;
        }
    }
    return {f,l};
}


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


// array is sorted
// lower bound :: nums[idx] >= x
// upper bound :: nums[idx] > x

// T.C. = O(logn + logn) = O(2logn)
// S.C. = O(1)
vector<int> searchRange(vector<int>& nums, int target) {

    int n = nums.size();
    int lb = lowerBound(nums,target);
    int ub = upperBound(nums,target);

    if(lb == n || nums[lb] != target) {
        return {-1,-1};
    }

    return {lb,ub-1};
}


// pure Binary Search
vector<int> searchRangeBS(vector<int>& nums, int target) {
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
        return {-1,-1};
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

    return {first,last};
}


int main()
{
    vector<int> nums = {2,4,6,8,8,8,11,13};
    int target = 8;
    vector<int> ans = searchRange(nums,target);

    for(int i = 0 ; i < ans.size() ; i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl; // 3 5 
    return 0;
}