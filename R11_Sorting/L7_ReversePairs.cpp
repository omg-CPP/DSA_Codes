// Leetcode : 493

// Given an integer array nums, return the number of reverse pairs in the array.

// A reverse pair is a pair (i, j) where:

// 0 <= i < j < nums.length and
// nums[i] > 2 * nums[j].

#include <iostream>
#include <vector>
using namespace std;

// Brute Force :: TLE
// T.C. = O(n^2)
// S.C. = O(1)
int reversePairsNaive(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    for(int i = 0 ; i < n ; i++) {
        for(int j = i+1 ; j < n ; j++) {
            if(nums[i] > (long long) 2 * nums[j]) {
                ans++;
            }
        }
    }
    return ans;
}

void merge(vector<int>& arr, int lo, int mid, int hi) {
    vector<int> temp;

    // first arr = [lo...mid]
    // second arr = [mid+1...hi]
    int left = lo;
    int right = mid+1;

    while(left <= mid && right <= hi) {
        if(arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else { // arr[left] > arr[right]
            temp.push_back(arr[right]);
            right++;
        }
    }

    if(left == mid+1) {
        while(right <= hi) {
            temp.push_back(arr[right]);
            right++;
        }
    }

    if(right == hi+1) {
        while(left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
    }

    for(int i = lo ; i <= hi ; i++) {
        arr[i] = temp[i-lo];
    }
}

int countPairs(vector<int>& arr, int lo, int mid, int hi) {
    int cnt = 0;
    int right = mid+1;
    for(int left = lo ;  left <= mid ; left++) {
        while(right <= hi && arr[left] > (long long) 2 * arr[right]) {
            right++;
        }
        cnt += (right - (mid+1));
    }
    return cnt;
}

int mS(vector<int>& arr, int lo, int hi) {
    int cnt = 0;
    int n = arr.size();
    if(lo == hi) {
        return cnt;
    }
    int mid = (lo + hi) / 2;
    cnt += mS(arr,lo,mid);
    cnt += mS(arr,mid+1,hi);
    cnt += countPairs(arr,lo,mid,hi);
    merge(arr,lo,mid,hi);
    return cnt;
}

// Optimal Approach
// T.C. = O(2nlogn)
// S.C. = O(n)
int reversePairs(vector<int>& nums) {
    int n = nums.size();
    int cnt = mS(nums,0,n-1);
    return cnt;
}

int main()
{
    vector<int> nums = {4,1,2,3,1};
    int cnt = reversePairs(nums);
    cout<<"The number of reverse pair is : "<<cnt<<endl;
    // The number of reverse pair is : 3
    return 0;
}