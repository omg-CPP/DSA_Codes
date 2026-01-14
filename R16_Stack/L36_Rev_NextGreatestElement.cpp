// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <climits>
#include <cmath>
using namespace std;

// Next Greatest Element Array Construction
// T.C. = O(n)
// S.C. = O(1)
// Reverse Loop Traversal for Linear Time Complexity

vector<int> nextGreatestElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> nge(n,0); // nge -> next greatest element array
    nge[n-1] = -1;
    int max = nums[n-1];
    for(int i = n-2 ; i >= 0 ; i--) {
        nge[i] = max;
        if(nums[i] > max) {
            max = nums[i];
        }
    }
    return nge;
}

int main()
{
    vector<int> nums = {3,7,1,9,0,6,2,8,5,4};
    for(int i = 0 ; i < nums.size() ; i++) {
        cout<<nums[i]<<" ";
    }
    // 3 7 1 9 0 6 2 8 5 4 
    cout<<endl;

    vector<int> ans = nextGreatestElement(nums);
    for(int i = 0 ; i < ans.size() ; i++) {
        cout<<ans[i]<<" ";
    }
    // 9 9 9 8 8 8 8 5 4 -1 
    cout<<endl;
    return 0;
}