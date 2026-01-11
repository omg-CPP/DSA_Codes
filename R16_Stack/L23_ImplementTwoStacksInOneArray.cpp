#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <climits>
#include <cmath>
using namespace std;

class twoStacks {
    int* arr;
    int size;
    int top1;
    int top2;

    public:

    twoStacks(int n) {
        arr = new int[n];
        size = n;
        top1 = -1;
        top2 = size;
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        // code here
        if(top1 < top2-1) {
            top1++;
            arr[top1] = x;
            cout<<"Element Pushed In Stack 1"<<endl;
        }
        else {
            cout<<"Stack Overflow"<<endl;
        }
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        // code here
        if(top2 > top1 + 1) {
            top2--;
            arr[top2] = x;
            cout<<"Element Pushed In Stack 2"<<endl;
        }
        else {
            cout<<"Stack Overflow"<<endl;
        }
    }

    // Function to remove an element from top of the stack1.   
    int pop1() {
        // code here
        if(top1 >= 0) {
            top1--;
            cout<<"Element Popped From Stack 1"<<endl;
        }
        else {
            cout<<"Stack Underflow"<<endl;
        }
    }

        
    // Function to remove an element from top of the stack2.
    int pop2() {
        // code here
        if(top2 <= size-1) {
            top2++;
            cout<<"Element Popped From Stack 2"<<endl;
        }
        else {
            cout<<"Stack Underflow"<<endl;
        }
    }
};

int main()
{
    twoStacks ts(6);
    ts.push1(10); // Element Pushed In Stack 1
    ts.pop2(); // Stack Underflow
    return 0;
}