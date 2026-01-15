// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <climits>
#include <cmath>
using namespace std;

// Next Smaller Element Index Array Construction
// T.C. = O(n)
// S.C. = O(n) : Stack Frames
// Reverse Loop traversal to acheive Linear Time Complexity

vector<int> nextSmallerElementIndex(vector<int>& nums) {
    int n = nums.size();
    vector<int> nsei(n,0); // nsei -> next smaller element index array
    stack<int> st;
    nsei[n-1] = -1;
    st.push(n-1);
    for(int i = n-2 ; i >= 0 ; i--) {
        while(st.size() > 0 && nums[i] <= nums[st.top()]) {
            st.pop();
        }
        if(st.size() == 0) {
            nsei[i] = -1;  // No next smaller element index exist for this particular element
        }
        else { // st.size() != 0
            nsei[i] = st.top();
        }
        st.push(i);
    }
    return nsei;
}

int main()
{
    vector<int> nums = {3,7,1,9,0,6,2,8,5,4};
    for(int i = 0 ; i < nums.size() ; i++) {
        cout<<nums[i]<<" ";
    }
    // 3 7 1 9 0 6 2 8 5 4 
    cout<<endl;

    vector<int> ans = nextSmallerElementIndex(nums);
    for(int i = 0 ; i < ans.size() ; i++) {
        cout<<ans[i]<<" ";
    }
    // 2 2 4 4 -1 6 -1 8 9 -1 
    cout<<endl;
    return 0;
}