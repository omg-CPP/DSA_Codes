// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <climits>
#include <cmath>
using namespace std;

// T.C. = O(N) + O(N) = O(2N)
// S.C. = O(N)

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int maxArea = 0;
    stack<int> st;
    for(int i = 0 ; i < n ; i++) {
        while(st.size() > 0 && heights[st.top()] >= heights[i]) {
            int ele = st.top();
            st.pop();
            int nse = i;
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(heights[ele] * (nse-pse-1),maxArea);
        }
        st.push(i);
    }
    while(st.size() != 0) {
        int ele = st.top();
        st.pop();
        int nse = n;
        int pse = st.empty() ? -1 : st.top();
        maxArea = max(heights[ele] * (nse-pse-1),maxArea);
    }
    return maxArea;
}

int main()
{
    vector<int> heights = {2,1,5,6,2,3};
    int maxArea = largestRectangleArea(heights);
    cout<<maxArea<<endl; // 10
    return 0;
}