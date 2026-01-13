// Leetcode : 1944
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <climits>
#include <cmath>
using namespace std;

vector<int> canSeePersonsCount(vector<int>& heights) {
    int n = heights.size();
    vector<int> ans(n,0);
    stack<int> st;
    st.push(heights[n-1]);
    ans[n-1] = 0;
    for(int i = n-2 ; i >= 0 ; i--) {
        int count = 0;
        // pop with count
        while(st.size() > 0 && heights[i] > st.top()) {
            st.pop();
            count++;
        }
        if(st.size() != 0) {
            count++;
        }
        ans[i] = count;
        // push
        st.push(heights[i]);
    }
    return ans;
}

int main()
{
    vector<int> heights = {10,6,8,5,11,9};
    vector<int> ans = canSeePersonsCount(heights);
    for(int i = 0 ; i < ans.size() ; i++) {
        cout<<ans[i]<<" ";
    }
    // 3 1 2 1 1 0 
    cout<<endl;
    return 0;
}