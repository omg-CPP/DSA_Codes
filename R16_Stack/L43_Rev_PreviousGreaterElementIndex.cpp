// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <climits>
#include <cmath>
using namespace std;

// Previous Greater Element Index Array Construction
// T.C. = O(n)
// S.C. = O(n) : Stack Frames
// Forward Loop traversal to acheive Linear Time Complexity

vector<int> previousGreaterElementIndex(vector<int>& nums) {
    int n = nums.size();
    vector<int> pgei(n,0); // pgei -> previous greater element index array
    stack<int> st;
    pgei[0] = -1;
    st.push(0);
    for(int i = 1 ; i < n ; i++) {
        while(st.size() > 0 && nums[i] >= nums[st.top()]) {
            st.pop();
        }
        if(st.size() == 0) {
            pgei[i] = -1;  // No previous greater element index  exist for this particular element
        }
        else { // st.size() != 0
            pgei[i] = st.top();
        }
        st.push(i);
    }
    return pgei;
}

int main()
{
    vector<int> nums = {3,7,1,9,0,6,2,8,5,4};
    for(int i = 0 ; i < nums.size() ; i++) {
        cout<<nums[i]<<" ";
    }
    // 3 7 1 9 0 6 2 8 5 4 
    cout<<endl;

    vector<int> ans = previousGreaterElementIndex(nums);
    for(int i = 0 ; i < ans.size() ; i++) {
        cout<<ans[i]<<" ";
    }
    // -1 -1 1 -1 3 3 5 3 7 8 
    cout<<endl;
    return 0;
}