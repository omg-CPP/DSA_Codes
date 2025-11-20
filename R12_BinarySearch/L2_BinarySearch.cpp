// Leetcode : 704

#include <iostream>
#include <vector>
using namespace std;

// Binary Search Algorithm
// Works only if Array is sorted
// - Ascending or - Descending
// works on array indices
// works on reduction in search space

// Iterative Approach (T.C.) : O(logn)

// 32 -> 16 -> 8 -> 4 -> 2 -> 1 ::: 6 steps
// n -> n/2 -> n/4 -> n/8 -> n/16 -> ------ -> 1
// n/(2^0) -> n/(2^1) -> n/(2^2) -> n/(2^3) -> ------ -> n/(2^t)
// t+1 steps = O(t+1)
// n/(2^t) = 1
// 2^t = n
// t*log2(2) = log2(n)
// t = logn
// T.C. = O(logn + 1) = O(logn)

// Overflow Case : 

// int mid = (lo + hi) / 2;
// mid = (lo + hi + lo - lo) / 2
// mid = (lo + lo) / 2 + (hi - lo) / 2
// mid = 2lo / 2 + (hi - lo) / 2
// mid = lo + (hi - lo) / 2

int search(vector<int>& nums, int target) {
    int n = nums.size();
    int lo = 0;
    int hi = n-1;
    // There should be a search space :: lo <= hi
    while(lo <= hi) {
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
    vector<int> arr = {1,2,4,5,9,15,18,21};
    // Search Space
    int target;
    cout<<"Enter element to be searched : ";
    cin>>target;
    int idx = -1;
    idx = search(arr,target);
    if(idx == -1) {
        cout<<target<<" is not present"<<endl;
    }
    else {
        cout<<target<<" is present at index : "<<idx<<endl;
    }
    return 0;
}

// Enter element to be searched : 18
// 18 is present at index : 6

// Enter element to be searched : 4
// 4 is present at index : 2

// Enter element to be searched : 21
// 21 is present at index : 7

// Enter element to be searched : 10
// 10 is not present

// Enter element to be searched : 24
// 24 is not present