#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;

void display(queue<int>& q) {
    int n = q.size();
    for(int i = 0 ; i < n ; i++) {
        int x = q.front();
        cout<<x<<" ";
        q.pop();
        q.push(x);
    }
    cout<<endl;
}

void reverseDisplay(queue<int>& q) {
    stack<int> st;
    queue<int> temp = q;  // Make a copy since we only want to display

    // Push elements into stack
    while(!temp.empty()) {
        st.push(temp.front());
        temp.pop();
    }

    // Display elements from stack (reverse order)
    while(!st.empty()) {
        cout<<st.top()<< " ";
        st.pop();
    }
    cout<<endl;
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    display(q); // 10 20 30 40 50 
    reverseDisplay(q); // 50 40 30 20 10
    display(q); // 10 20 30 40 50 
    return 0;
}