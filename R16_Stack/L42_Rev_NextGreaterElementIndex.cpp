// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <climits>
#include <cmath>
using namespace std;

// Next Greater Element Index Array Construction
// T.C. = O(n)
// S.C. = O(n) : Stack Frames
// Reverse Loop traversal to acheive Linear Time Complexity

vector<int> nextGreaterElementIndex(vector<int>& nums) {
    int n = nums.size();
    vector<int> ngei(n,0); // ngei -> next greater element index  array
    stack<int> st;
    ngei[n-1] = -1;
    st.push(n-1);
    for(int i = n-2 ; i >= 0 ; i--) {
        while(st.size() > 0 && nums[i] >= nums[st.top()]) {
            st.pop();
        }
        if(st.size() == 0) {
            ngei[i] = -1;  // No next greater element index exist for this particular element
        }
        else { // st.size() != 0
            ngei[i] = st.top();
        }
        st.push(i);
    }
    return ngei;
}

int main()
{
    vector<int> nums = {3,7,1,9,0,6,2,8,5,4};
    for(int i = 0 ; i < nums.size() ; i++) {
        cout<<nums[i]<<" ";
    }
    // 3 7 1 9 0 6 2 8 5 4 
    cout<<endl;

    vector<int> ans = nextGreaterElementIndex(nums);
    for(int i = 0 ; i < ans.size() ; i++) {
        cout<<ans[i]<<" ";
    }
    // 1 3 3 -1 5 7 7 -1 -1 -1 
    cout<<endl;
    return 0;
}