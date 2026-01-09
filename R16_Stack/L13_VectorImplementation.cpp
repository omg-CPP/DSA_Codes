#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Stack { // user defined data structure
public :
    vector<int> v;

    Stack() {
        
    }

    void push(int val) {
        // no overflow condition
        v.push_back(val);
    }

    void pop() {
        if(v.size() == 0) {
            cout<<"Stack is empty : Stack Underflow"<<endl;
        }
        else {
            v.pop_back();
        }
    }

    int top() {
        if(v.size() == 0) {
            cout<<"Stack is empty : Stack Underflow"<<endl;
            return -1;
        }
        return v[v.size()-1];
    }

    int size() {
        return v.size();
    }
};

int main()
{
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    cout<<st.top()<<endl; // 50

    cout<<st.size()<<endl; // 5

    st.pop();
    st.pop();

    cout<<st.size()<<endl; // 3

    cout<<st.top()<<endl; // 30

    st.push(100);
    st.push(200);

    cout<<st.top()<<endl; // 200
    cout<<st.size()<<endl; // 5

    st.push(300); 

    cout<<st.top()<<endl; // 300
    cout<<st.size()<<endl; // 6

    st.pop();
    st.pop();
    st.pop();
    st.pop();

    cout<<st.top()<<endl; // 20
    cout<<st.size()<<endl; // 2

    st.pop(); 

    cout<<st.top()<<endl; // 10
    cout<<st.size()<<endl; // 1

    // v.size() == 1
    st.pop();
    // v.size() == 0

    st.pop(); // Stack is empty : Stack Underflow
    return 0;
}