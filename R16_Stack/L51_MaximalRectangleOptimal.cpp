// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <climits>
#include <cmath>
using namespace std;

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

// T.C. = O(M*N) + O(M) * O(2N) 
//      = O(M*N) + O(M*2N)
// S.C. = O(M*N) + O(M)
int maximalRectangle(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int maxArea = 0;
    vector<vector<int>> prefixSum(m,vector<int>(n,0));
    for(int j = 0 ; j < n ; j++) {
        int sum = 0;
        for(int i = 0 ; i < m ; i++) {
            sum = sum + matrix[i][j];
            if(matrix[i][j] == 0) {
                sum = 0;
            }
            prefixSum[i][j] = sum;
        }
    }
    for(int i = 0 ; i < m ; i++) {
        maxArea = max(maxArea,largestRectangleArea(prefixSum[i]));
    }
    return maxArea;
}

int main()
{
    // vector<vector<char>> matrix = {{'1','0','1','0','0'},
    //                                {'1','0','1','1','1'},
    //                                {'1','1','1','1','1'},
    //                                {'1','0','0','1','0'}};
    vector<vector<int>> matrix = {{1,0,1,0,0},
                                   {1,0,1,1,1},
                                   {1,1,1,1,1},
                                   {1,0,0,1,0}};
    int maxArea = maximalRectangle(matrix);
    cout<<maxArea<<endl; // 6
    return 0;
}