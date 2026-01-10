#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <climits>
#include <cmath>
using namespace std;

// previous greater index
vector<int> stockSpan(vector<int>& stocks) {
    int n = stocks.size();
    vector<int> span(n,0);
    vector<int> pgi(n,0);
    stack<int> st;
    pgi[0] = -1;
    st.push(0);
    for(int i = 1 ; i < n ; i++) {
        // pop all the elements smaller than or equal to num[i]
        while(st.size() > 0 && stocks[st.top()] <= stocks[i]) {
            st.pop();
        }
        // mark the ans in result vector
        if(st.size() == 0) {
            pgi[i] = -1;
        }
        else {
            pgi[i] = st.top();
        }
        // push that particular nums[i] for next iteration
        st.push(i);
    }
    for(int i = 0 ; i < n ; i++) {
        span[i] = i - pgi[i];
    }
    return span;
}

int main()
{
    vector<int> stocks = {100,80,60,70,60,75,85};
    for(int i = 0 ; i < stocks.size() ; i++) {
        cout<<stocks[i]<<" ";
    }
    // 3 1 2 7 4 6 2 3 
    cout<<endl;

    vector<int> span = stockSpan(stocks);
    for(int i = 0 ; i < span.size() ; i++) {
        cout<<span[i]<<" ";
    }
    // pgi : -1 0 1 1 3 1 0 
    // span : 1 1 1 2 1 4 6 
    cout<<endl;
    return 0;
}