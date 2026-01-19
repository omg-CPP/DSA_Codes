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

class Queue {
public :
    int f; // front
    int b; // back
    vector<int> v; // vector
    Queue(int n) {
        f = 0;
        b = 0;
        v.resize(n);
    }

    void push(int val) {
        if(b == v.size()) {
            cout<<"Queue is Full"<<endl;
            return;
        }
        else {
            v[b] = val;
            b++;
        }
    }

    void pop() {
        if(b-f == 0) {
            cout<<"Queue is Empty"<<endl;
            return;
        }
        else {
            f++;
        }
    }

    int front() {
        if(b-f == 0) {
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        else {
            return v[f];
        }
    }

    int back() { // rear element
        if(b-f == 0) {
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        else {
            return v[b-1];
        }
    }

    int size() {
        return b-f;
    }

    bool empty() {
        if(b-f == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    void display() {
        for(int i = f ; i < b ; i++) {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }

};

int main()
{
    int n = 5;
    Queue q(n);
    cout<<q.empty()<<endl; // 1
    q.pop(); // Queue is Empty
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout<<q.empty()<<endl; // 0
    q.display(); // 10 20 30 40 
    cout<<q.front()<<endl; // 10
    cout<<q.back()<<endl; // 40
    cout<<q.size()<<endl; // 4
    q.push(50);
    q.push(60); // Queue is Full
    cout<<q.size()<<endl; // 5
    q.display(); // 10 20 30 40 50 
    q.pop();
    cout<<q.front()<<endl; // 20
    cout<<q.back()<<endl; // 50
    cout<<q.size()<<endl; // 4
    q.display(); // 20 30 40 50
    return 0;
}