// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <climits>
#include <cmath>
using namespace std;

// Previous Smaller Element Array Construction
// T.C. = O(n)
// S.C. = O(n) : Stack Frames
// Forward Loop traversal to acheive Linear Time Complexity

vector<int> previousSmallerElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> pse(n,0); // nge -> previous smaller element array
    stack<int> st;
    pse[0] = -1;
    st.push(nums[0]);
    for(int i = 1 ; i < n ; i++) {
        while(st.size() > 0 && nums[i] <= st.top()) {
            st.pop();
        }
        if(st.size() == 0) {
            pse[i] = -1;  // No previous smaller element exist for this particular element
        }
        else { // st.size() != 0
            pse[i] = st.top();
        }
        st.push(nums[i]);
    }
    return pse;
}

int main()
{
    vector<int> nums = {3,7,1,9,0,6,2,8,5,4};
    for(int i = 0 ; i < nums.size() ; i++) {
        cout<<nums[i]<<" ";
    }
    // 3 7 1 9 0 6 2 8 5 4 
    cout<<endl;

    vector<int> ans = previousSmallerElement(nums);
    for(int i = 0 ; i < ans.size() ; i++) {
        cout<<ans[i]<<" ";
    }
    // -1 3 -1 1 -1 0 0 2 2 2
    cout<<endl;
    return 0;
}