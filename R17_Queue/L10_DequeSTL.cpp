#include <bits/stdc++.h>
#include <iostream>
#include <deque>
using namespace std;
int main()
{
    deque<int> dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);
    dq.push_back(40);
    for(int i = 0 ; i < dq.size() ; i++) {
        cout<<dq[i]<<" ";
    }
    // 10 20 30 40 
    cout<<endl; 
    dq.pop_back();
    dq.pop_back();
    dq.push_front(15);
    dq.push_front(25);
    dq.push_front(35);
    dq.push_front(45);
    for(int i = 0 ; i < dq.size() ; i++) {
        cout<<dq[i]<<" ";
    }
    // 45 35 25 15 10 20 
    cout<<endl; 
    dq.pop_front();
    dq.pop_front();
    for(int i = 0 ; i < dq.size() ; i++) {
        cout<<dq[i]<<" ";
    }
    // 25 15 10 20 
    cout<<endl; 
    cout<<dq.front()<<endl; // 25
    cout<<dq.back()<<endl; // 20
    cout<<dq.size()<<endl; // 4
    return 0;
}