#include <bits/stdc++.h>
#include <iostream>
#include <stack>
using namespace std;

void displayStack(stack<int> st) { // Pass by value : Deep Copy
    while(st.size() > 0) {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    displayStack(st); // 50 40 30 20 10 
    // Original Stack st is preserved
    cout<<st.size()<<endl; // 5
    return 0;
}