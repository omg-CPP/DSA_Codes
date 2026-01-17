// Leetcode : 84

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <climits>
#include <cmath>
using namespace std;

// T.C. = 2 * O(2N) + O(N) = O(4N) + O(N) = O(5N)
// S.C. = O(2N) + O(2N) = O(4N)

// T.C. = O(2N)
vector<int> previousSmallerElementIndex(vector<int>& heights) {
    int n = heights.size();
    vector<int> psei(n,-1);
    stack<int> st;
    st.push(0);
    for(int i = 1 ; i < n ; i++) {
        while(st.size() > 0 && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        if(st.size() == 0) {
            psei[i] = -1;
        }
        else {
            psei[i] = st.top();
        }
        st.push(i);
    }
    return psei;
}

// T.C. = O(2N)
vector<int> nextSmallerElementIndex(vector<int>& heights) {
    int n = heights.size();
    vector<int> nsei(n,n);
    stack<int> st;
    st.push(n-1);
    for(int i = n-2 ; i >= 0 ; i--) {
        while(st.size() > 0 && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        if(st.size() == 0) {
            nsei[i] = n;
        }
        else {
            nsei[i] = st.top();
        }
        st.push(i);
    }
    return nsei;
}

// T.C. = O(N)
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> psei = previousSmallerElementIndex(heights);
    vector<int> nsei = nextSmallerElementIndex(heights);
    int maxArea = INT_MIN;
    for(int i = 0 ; i < n ; i++) {
        int area = heights[i] * (nsei[i]-psei[i]-1);
        if(area > maxArea) {
            maxArea = area;
        }
    }
    return maxArea;
}

int main()
{
    vector<int> heights = {2,1,5,6,2,3};
    vector<int> psei = previousSmallerElementIndex(heights);
    for(int i = 0 ; i < psei.size() ; i++) {
        cout<<psei[i]<<" ";
    }
    // -1 -1 1 2 1 4 
    cout<<endl;

    vector<int> nsei = nextSmallerElementIndex(heights);
    for(int i = 0 ; i < nsei.size() ; i++) {
        cout<<nsei[i]<<" ";
    }
    // 1 6 4 4 6 6 
    cout<<endl;

    int maxArea = largestRectangleArea(heights);
    cout<<maxArea<<endl; // 10
    return 0;
}