#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// val < min
// val - min < 0
// val + (val - min) < val
// 2 * val - min < val

// 2 * newMin  - oldMin = st.top()
// oldMin = 2 * newMin - st.top()

// T.C. = O(1)
// S.C. = O(1)

class MinStack {
public:

    stack<long long> st;
    long long mn;
    MinStack() {
        mn = LLONG_MAX;
    }
    
    void push(int val) { // O(1)
        long long x = (long long)val;
        if(st.size() == 0) {
            st.push(x);
            mn = x;
        }
        else if(x >= mn) {
            st.push(x);
        }
        else { // val < mn
            // update has been done
            st.push(2*x - mn);
            mn = x;
        }
    }
    
    void pop() { // O(1)
        if(st.top() >= mn) {
            st.pop();
        }
        else { // st.top() < mn
            // update has been done
            // oldMin = 2*newMin - st.top()
            mn = 2*mn - st.top();
            st.pop();
        }
    }
    
    int top() { // O(1)
        if(st.top() < mn) {
            return (int)mn;
        }
        else { 
            return(int)st.top();
        }
    }
    
    int getMin() { // O(1)
        return (int)mn;
    }
};

int main()
{
    return 0;
}