#include <iostream>
#include <vector>
using namespace std;

// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

// Could you solve the problem in linear time and in O(1) space?

// Definition: The floor of a real number x is the largest integer that is less than or equal to x.
// Floor(3.7) = 3
// Floor(-2.3) = -3

// Definition: The ceiling of a real number x is the smallest integer that is greater than or equal to x.
// Ceiling(3.7) = 4
// Celing(-2.3) = -2

int majorityElementBruteForce(vector<int>& nums) {
    // Time Complexity : O(n^2)
    int n = nums.size();
    for(int i = 0 ; i < n ; i++) {
        int count = 0;
        for(int j = 0 ; j < n ; j++) {
            if(nums[j] == nums[i]) {
                count++;
            }
        }
        if(count > n/2) {
            return nums[i];
        }
    }
}

int majorityElement(vector<int>& nums) {
    // Moore Voting Algorithm
    // Time Complexity : O(n)
    // Space : O(1)
    int n = nums.size();
    int count = 0;
    int element;
    for(int i = 0 ; i < n ; i++) {
        if(count == 0) {
            count = 1;
            element = nums[i];
        }
        else if(nums[i] == element) {
            count++;
        }
        else {
            count--;
        }
    }
    int cnt;
    for(int i = 0 ; i < n ; i++) {
        if(nums[i] == element) {
            cnt++;
        }
    }
    if(cnt > n/2) {
        return element;
    }
    return -1;
}
    
int main()
{
    vector<int> nums = {2,2,1,1,1,2,2};
    int ans = majorityElementBruteForce(nums);
    cout<<ans<<endl; // 2

    vector<int> arr = {7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5};
    int res = majorityElement(arr);
    cout<<res<<endl; // 5
    return 0;
}