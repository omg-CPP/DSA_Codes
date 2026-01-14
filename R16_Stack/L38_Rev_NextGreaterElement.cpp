// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <climits>
#include <cmath>
using namespace std;

// Next Greater Element Array Construction
// T.C. = O(n)
// S.C. = O(n) : Stack Frames
// Reverse Loop traversal to acheive Linear Time Complexity

vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> nge(n,0); // nge -> next greater element array
    stack<int> st;
    nge[n-1] = -1;
    st.push(nums[n-1]);
    for(int i = n-2 ; i >= 0 ; i--) {
        while(st.size() > 0 && nums[i] >= st.top()) {
            st.pop();
        }
        if(st.size() == 0) {
            nge[i] = -1;  // No next greater element exist for this particular element
        }
        else { // st.size() != 0
            nge[i] = st.top();
        }
        st.push(nums[i]);
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

    vector<int> ans = nextGreaterElement(nums);
    for(int i = 0 ; i < ans.size() ; i++) {
        cout<<ans[i]<<" ";
    }
    // 7 9 9 -1 6 8 8 -1 -1 -1 
    cout<<endl;
    return 0;
}