#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// T.C. = O(n) + O(n) = O(n)
// S.C. = O(1)
vector<int> firstNegativeNumber(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> ans(n-k+1,0); // size = n-k+1
    int p = -1;
    for(int i = 0 ; i < k ; i++) {
        if(nums[i] < 0) {
            p = i;
            break;
        }
    }
    if(p == -1) {
        ans[0] = 1;
    }
    else {
        ans[0] = nums[p];
    }

    // Sliding Window Algorithm
    int i = 1;
    int j = k;
    while(j < n) {
        if(p >= i) {
            ans[i] = nums[p];
        }
        else { // p < i
            p = -1;
            // This loops works for atmost n times in total
            for(int x = i ; x <= j ; x++) {
                if(nums[x] < 0) {
                    p = x;
                    break;
                }
            }
            if(p != -1) {
                ans[i] = nums[p];
            }
            else {
                ans[i] = 1;
            }
        }
        i++;
        j++;
    }
    return ans;
}

int main()
{
    vector<int> nums = {2,-3,4,4,-7,-1,4,-2,6};
    for(int i = 0 ; i < nums.size() ; i++) {
        cout<<nums[i]<<" ";
    }
    // 2 -3 4 4 -7 -1 4 -2 6 
    cout<<endl;
    int k = 4;
    vector<int> ans = firstNegativeNumber(nums,k);
    for(int i = 0 ; i < ans.size() ; i++) {
        cout<<ans[i]<<" ";
    }
    // -3 -3 -7 -7 -7 -1 
    cout<<endl;
    return 0;
}