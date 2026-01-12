#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <climits>
#include <cmath>
using namespace std;

int priority(char ch) {
    if(ch == '+' || ch == '-') {
        return 1;
    }
    else { // ch == '*' || ch == '/'
        return 2;
    }
}

int solve(int val1, int val2, char ch) {
    if(ch == '+') {
        return val1 + val2;
    }
    else if(ch == '-') {
        return val1 - val2;
    }
    else if(ch == '*') {
        return val1 * val2;
    }
    else { // ch == '/'
        return val1 / val2;
    }
}

int main()
{
    string s = "1+(2+6)*4/8-3"; // infix operation
    // string s = "(7+9)*4/8-3"; // 5
    // we will need two stacks, one for val and other for operator
    stack<int> val;
    stack<char> op;

    for(int i = 0 ; i < s.size() ; i++) {
        // check if s[i] is a digit (0-9) 
        int ascii = (int)(s[i]);
        if(ascii >= 48 && ascii <= 57) { // digit
            val.push(ascii-48); 
        }
        else { // s[i] is +,-,*,/,(,)
            if(op.size() == 0) {
                op.push(s[i]);
            }
            else if(s[i] == '(') {
                op.push(s[i]);
            }
            else if(op.top() == '(') {
                op.push(s[i]);
            }
            else if(s[i] == ')') {
                while(op.top() != '(') {
                    // work
                    char ch = op.top();
                    op.pop();
                    int val2 = val.top();
                    val.pop();
                    int val1 = val.top();
                    val.pop();
                    int ans = solve(val1,val2,ch);
                    val.push(ans);
                }
                op.pop(); // opening bracket ko uda diya
            }
            else if(priority(s[i]) > priority(op.top())) {
                op.push(s[i]);
            }
            else { // (priority(s[i]) <= priority(op.top()))
                // work
                while(op.size() > 0 && priority(s[i]) <= priority(op.top())) {
                    char ch = op.top();
                    op.pop();
                    int val2 = val.top();
                    val.pop();
                    int val1 = val.top();
                    val.pop();
                    int ans = solve(val1,val2,ch);
                    val.push(ans);
                }
                op.push(s[i]);
            }
        }
    }
    // the operator stack can have values.
    // so make it empty.
    while(op.size() > 0) {
        // work
        char ch = op.top();
        op.pop();
        int val2 = val.top();
        val.pop();
        int val1 = val.top();
        val.pop();
        int ans = solve(val1,val2,ch);
        val.push(ans);
    }
    cout<<val.top()<<endl; // 2
    cout<<1+(2+6)*4/8-3<<endl; // 2
    return 0;
}