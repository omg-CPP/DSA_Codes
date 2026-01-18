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

// Consider 0 based indexing
void removeElementsAtEvenPositions(queue<int>& q) {
    int n = q.size();
    for(int i = 0 ;i < n ; i++) {
        if(i % 2 == 0) { // if element is present at even position index
            q.pop();
        }
        else { // if element is present at odd position index
            int x = q.front();
            q.pop();
            q.push(x);
        }
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
    removeElementsAtEvenPositions(q);
    display(q); // 20 40 
    return 0;
}