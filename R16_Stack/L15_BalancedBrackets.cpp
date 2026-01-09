#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isBalanced(string s) {
    if(s.size() % 2 != 0) {
        return false;
    }
    stack<char> st;
    for(int i = 0 ; i < s.size() ; i++) {
        if(s[i] == '(') {
            st.push(s[i]);
        }
        else { // s[i] == ')'
            if(st.size() == 0) {
                return false;
            }
            else { // st.size > 0 
                // st.top() == '('
                // as we are only pushing '('
                st.pop();
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
    string s1 = "()()()";
    cout<<isBalanced(s1)<<endl; // 1
    string s2 = "()(()(";
    cout<<isBalanced(s2)<<endl; // 0
    return 0;
}