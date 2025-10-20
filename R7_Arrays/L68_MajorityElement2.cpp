#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

vector<int> majorityElementBruteForce(vector<int>& nums) {
    // Time Complexity : O(n^2)
    vector<int> majority;
    int n = nums.size();
    for(int i = 0 ; i < n ; i++) {
        if(majority.size() == 0 || majority[0] != nums[i]) {
            int count = 0;
            for(int j = 0 ; j < n ; j++) {
                if(nums[j] == nums[i]) {
                    count++;
                }
            }
            if(count > n/3) {
                majority.push_back(nums[i]);
            }
        }
        if(majority.size() == 2) {
            break;
        }
    }
    return majority;
}

vector<int> majorityElement(vector<int>& nums) {
    // Consider using Boyer-Moore Voting Algorithm, which is efficient for finding elements that appear more than a certain threshold.
    // Optimal Approach
    // Time Complexity : O(2n)
    vector<int> majority;
    int n = nums.size();
    int cnt1 = 0;
    int cnt2 = 0;
    int ele1 = INT_MIN;
    int ele2 = INT_MIN;
    for(int i = 0 ;i < n ; i++) {
        if(cnt1 == 0 && nums[i] != ele2) {
            cnt1 = 1;
            ele1 = nums[i];
        }
        else if(cnt2 == 0 && nums[i] != ele1) {
            cnt2 = 1;
            ele2 = nums[i];
        }
        else if(nums[i] == ele1) {
            cnt1++;
        }
        else if(nums[i] == ele2) {
            cnt2++;
        }
        else {
            cnt1--;
            cnt2--;
        }
    }
    // again made pointers as 0
    cnt1 = 0;
    cnt2 = 0;
    // manual check
    for(int i = 0 ; i < n ; i++) {
        if(ele1 == nums[i]) {
            cnt1++;
        }
        if(ele2 == nums[i]) {
            cnt2++;
        }
    }
    int val = (int)(n/3) + 1;
    if(cnt1 >= val) {
        majority.push_back(ele1);
    }
    if(cnt2 >= val) {
        majority.push_back(ele2);
    }
    sort(majority.begin(),majority.end());
    return majority;
}


int main()
{
    vector<int> arr = {1,1,1,3,3,2,2,2};
    vector<int> ans = majorityElementBruteForce(arr);
    for(int i = 0 ; i < ans.size() ; i++) {
        cout<<ans[i]<<" ";
    }
    // 1 2 
    cout<<endl;

    vector<int> res = majorityElement(arr);
    for(int i = 0 ; i < res.size() ; i++) {
        cout<<res[i]<<" ";
    }
    // 1 2 
    cout<<endl;
    return 0;
}