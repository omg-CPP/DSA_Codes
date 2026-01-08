#include <bits/stdc++.h>
#include <iostream>
#include <stack>
using namespace std;

// Pass by reference : Shallow Copy
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

// Pass by reference : Shallow Copy
void pushAtBottom(stack<int>& st, int val) {
    stack<int> helper;
    while(st.size() > 0) {
        helper.push(st.top());
        st.pop();
    }
    st.push(val);
    while(helper.size() > 0) {
        st.push(helper.top());
        helper.pop();
    }
}

// Pass by reference : Shallow Copy
void pushAtAnyIndex(stack<int>& st, int idx, int val) {
    stack<int> helper;
    while(st.size() > idx) {
        helper.push(st.top());
        st.pop();
    }
    st.push(val);
    while(helper.size() > 0) {
        st.push(helper.top());
        helper.pop();
    }
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
    // 50 is at top and 10 is at the bottom
    // 10 20 30 40 50 

    pushAtBottom(st,80); // push 80 at bottom of the stack

    displayStack(st);
    // 80 10 20 30 40 50 

    pushAtAnyIndex(st,2,110);

    displayStack(st);
    // 80 10 110 20 30 40 50 
    
    return 0;
}