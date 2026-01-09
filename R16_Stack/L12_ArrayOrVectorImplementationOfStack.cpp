#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Stack { // user defined data structure
public :
    int arr[5];
    int idx;

    Stack() {
        idx = -1;
    }

    void push(int val) {
        if(idx == 4) {
            cout<<"Stack is Full : Stack Overflow"<<endl;
        }
        else {
            idx++;
            arr[idx] = val;
        }
    }

    void pop() {
        if(idx == -1) {
            cout<<"Stack is empty : Stack Underflow"<<endl;
        }
        else {
            idx--;
        }
    }

    int top() {
        if(idx == -1) {
            cout<<"Stack is empty : Stack Underflow"<<endl;
            return -1;
        }
        else {
            return arr[idx];
        }
    }

    int size() {
        return idx+1;
    }

    void display() {
        if(idx == -1) {
            cout<<"Stack Underflow"<<endl;
        }
        else {
            for(int i = 0 ; i <= idx ; i++) {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
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

    st.display(); // 10 20 30 40 50 

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

    st.push(300); // Stack is Full : Stack Overflow

    cout<<st.top()<<endl; // 200
    cout<<st.size()<<endl; // 5

    st.pop();
    st.pop();
    st.pop();
    st.pop();

    cout<<st.top()<<endl; // 10
    cout<<st.size()<<endl; // 1

    // idx = 0
    st.pop(); 
    // idx = -1


    cout<<st.top()<<endl; 
    // Stack is empty : Stack Underflow
    // -1
    cout<<st.size()<<endl; // 0

    st.pop(); // Stack is empty : Stack Underflow

    st.display(); // Stack Underflow

    return 0;
}