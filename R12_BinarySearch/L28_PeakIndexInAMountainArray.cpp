// Leetcode : 852
// 3 <= arr.length <= 105
// You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.
// Return the index of the peak element.
// Your task is to solve it in O(log(n)) time complexity.

#include <iostream>
#include <vector>
using namespace std;

// T.C. = O(logn) 
// S.C. = O(1)
int peakIndexInMountainArray(vector<int>& arr) {
    // single peak
    // Binary Search
    int n = arr.size();
    int lo = 1;
    int hi = n-2;
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) {
            return mid;
        }
        // if mid is in increasing part
        else if(arr[mid] > arr[mid-1]) {
            lo = mid + 1;
        }
        // if mid is in decreasing part
        else { // arr[mid] > arr[mid+1]
            hi = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {0,10,5,2};
    cout<<peakIndexInMountainArray(arr)<<endl; // 1
    return 0;
}