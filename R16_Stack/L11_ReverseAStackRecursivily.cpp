#include <bits/stdc++.h>
#include <iostream>
#include <stack>
using namespace std;

void displayStack(stack<int>& st) { 
    stack<int> temp;
    while(st.size() > 0) {
        temp.push(st.top());
        st.pop();
    }
    // moving elements back to st
    while(temp.size() > 0) {
        cout<<temp.top()<<" ";
        st.push(temp.top());
        temp.pop();
    }
    cout<<endl;
}

void pushAtBottom(stack<int>& st, int val) {
    if(st.size() == 0) {
        st.push(val);
        return;
    }
    int x = st.top();
    st.pop();
    pushAtBottom(st,val);
    st.push(x);
}

void reverseStack(stack<int>& st) {
    if(st.size() == 1) {
        return;
    }
    int x = st.top();
    st.pop();
    reverseStack(st);
    pushAtBottom(st,x);
}

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    displayStack(st);
    // 10 20 30 40 50 

    reverseStack(st);

    displayStack(st);
    // 50 40 30 20 10 
    return 0;
}