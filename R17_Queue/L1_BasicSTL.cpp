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
int main()
{
    queue<int> q;
    // push
    // pop
    // front
    // size, empty
    // back
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    cout<<q.size()<<endl; // 5
    cout<<q.front()<<endl; // 10
    cout<<q.back()<<endl; // 50
    q.pop();
    cout<<q.size()<<endl; // 4
    cout<<q.front()<<endl; // 20
    cout<<q.back()<<endl; // 50
    return 0;
}