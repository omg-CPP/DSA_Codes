// Leetcode : 155 
#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

// T.C. = O(1) for each operation
// S.C. = O(2n) for storing pair value in stack

class MinStack {
public:
    stack<pair<int,int>> st;
    MinStack() {
        // Default Constructor
    }
    
    void push(int val) {
        if(st.size() == 0) {
            // first element case
            st.push({val,val});
        }
        else {
            st.push({val,min(val,st.top().second)});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

int main()
{
    return 0;
}


// O(n) time : Brute Force

// stack<int> st;
// int getMin() {
//     stack<int> helper;
//     int mn = INT_MAX;
//     while(st.size() > 0) {
//         mn = min(mn,st.top());
//         helper.push(st.top());
//         st.pop();
//     }
//     while(helper.size() > 0) {
//         st.push(helper.top());
//         helper.pop();
//     }
//     return mn;
// }