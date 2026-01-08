#include <bits/stdc++.h>
#include <iostream>
#include <stack>
using namespace std;


// without using extra helper stack
// T.C. = O(n)
// S.C. = O(n)
void displayStackRecursive(stack<int>& st) {
    if(st.size() == 0) {
        return;
    }
    int x = st.top();
    st.pop();
    displayStackRecursive(st);
    cout<<x<<" ";
    st.push(x);
}

// without using extra helper stack
// T.C. = O(n)
// S.C. = O(n)
void displayReverseStackRecursive(stack<int>& st) {
    if(st.size() == 0) {
        return;
    }
    int x = st.top();
    cout<<x<<" ";
    st.pop();
    displayReverseStackRecursive(st);
    st.push(x);
}

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    displayReverseStackRecursive(st);
    // 50 40 30 20 10 
    cout<<endl;

    displayStackRecursive(st);
    // 10 20 30 40 50 
    cout<<endl;
    return 0;
}