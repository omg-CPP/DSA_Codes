// Leetcode : 155 
#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

// T.C. = O(1) for each operation
// S.C. = O(2n) for storing values in two different stacks

class MinStack {
public:
    stack<int> st;
    stack<int> helper;
    MinStack() {
        // Default Constructor
    }
    
    void push(int val) {
        st.push(val);
        if(helper.size() == 0 || val < helper.top()) {
            helper.push(val);
        }
        else { // val >= helper.top()
            helper.push(helper.top());
        }
    }
    
    void pop() {
        st.pop();
        helper.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return helper.top();
    }
};

int main()
{
    return 0;
}