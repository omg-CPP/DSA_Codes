// Leetcode : 20

// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.

#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <climits>
#include <cmath>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for(int i = 0 ; i < s.size() ; i++) {
        if(st.size() == 0) {
            if(s[i] == ')' || s[i] == '}' || s[i] == ']') {
                return false;
            }
        }
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        }
        else { 
            if(s[i] == ')') {
                if(st.top() == '(') {
                    st.pop();
                }
                else {
                    return false;
                }
            }
            if(s[i] == '}') {
                if(st.top() == '{') {
                    st.pop();
                }
                else {
                    return false;
                }
            }
            if(s[i] == ']') {
                if(st.top() == '[') {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }
    }
    if(st.size() == 0) {
        return true;
    }
    else {
        return false;
    }
}
int main()
{
    return 0;
}