#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <climits>
#include <cmath>
using namespace std;
int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    // st : 50 40 30 20 10

    stack<int> temp;
    while(st.size() > 0) {
        temp.push(st.top());
        st.pop();
    }

    stack<int> gt;
    while(temp.size() > 0) {
        gt.push(temp.top());
        temp.pop();
    }

    while(gt.size() > 0) {
        cout<<gt.top()<<" ";
        gt.pop();
    }
    // gt : 50 40 30 20 10
    cout<<endl;
    return 0;
}