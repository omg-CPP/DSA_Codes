// Leetcode : 1283
// Binary Search On Answers

// arr = {1,2,5,9}
// threshold = 6
// take ceil value upon division
// t = 1 :: 1 + 2 + 5 + 9 = 17 > 6
// t = 2 :: 1 + 1 + 3 + 5 = 10 > 6
// t = 3 :: 1 + 1 + 2 + 3 = 7 > 6
// t = 4 :: 1 + 1 + 2 + 3 = 7 > 6
// t = 5 :: 1 + 1 + 1 + 2 = 5 <= 6 
// t = 5 is the required ans

// also after t >= maxElement(9) it will always give 4 as the sum

// so range will be [1,maxElement(arr)]
// [1,9]

#include <iostream>
#include <climits>
#include <cmath>
#include <vector>
using namespace std;

int findMax(vector<int>& nums) {
    int n = nums.size();
    int maxElement = INT_MIN;
    for(int i = 0 ; i < n ; i++) {
        maxElement = max(maxElement,nums[i]);
    }
    return maxElement;
}

int possibleDivisor(vector<int>& nums, int t, int threshold) {
    int n = nums.size();
    int sum = 0;
    for(int i = 0 ; i < n ; i++) {
        sum += ceil((double)nums[i]/(double)t);
    }
    if(sum <= threshold) {
        return true;
    }
    else {
        return false;
    }
}

// T.C. = O(max(arr)*n)
// S.C. = O(1)
int smallestDivisorBruteForce(vector<int>& nums, int threshold) {
    int n = nums.size();
    for(int i = 1 ; i <= findMax(nums) ; i++) {
        if(possibleDivisor(nums,i,threshold) == true) {
            return i;
        }
    }
    return -1;
}

// Binary Search On Answers
// T.C. = O(log(max(arr))*n)
// S.C. = O(1)
int smallestDivisor(vector<int>& nums, int threshold) {
    int n = nums.size();
    // n -> minimum sum
    if(threshold < n) {
        return -1;
    }
    int lo = 1;
    int hi = findMax(nums);
    int ans = 0;
    while(lo <= hi) {
        int mid = lo + (hi-lo) / 2;
        if(possibleDivisor(nums,mid,threshold) == true) {
            ans = mid;
            hi = mid-1;
        }
        else { // possibleDivisor(nums,mid,threshold) == false
            lo = mid+1;
        }
    }
    return ans;
    // return lo;
}

int main()
{
    vector<int> nums = {1,2,5,9};
    int threshold = 6;
    cout<<smallestDivisorBruteForce(nums,threshold)<<endl; // 5
    cout<<smallestDivisor(nums,threshold)<<endl; // 5
    return 0;
}