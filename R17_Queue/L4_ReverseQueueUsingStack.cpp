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

void reverseQueueUsingStack(queue<int>& q) {
    stack<int> st;
    // empty the queue into stack
    while(q.size() > 0) {
        int x = q.front();
        st.push(x);
        q.pop();
    }
    // empty the stack into queue
    while(st.size() > 0) {
        int x = st.top();
        q.push(x);
        st.pop();
    }
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
    reverseQueueUsingStack(q);
    display(q); // 50 40 30 20 10 
    return 0;
}