#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <climits>
#include <cmath>
using namespace std;

// Prefix Evaluation

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
    string s = "-/*+79483"; 
    // we will need one stacks, one for val
    stack<int> val;

    for(int i = s.size()-1 ; i >= 0 ; i--) { // reverse loop
        // check if s[i] is a digit (0-9) 
        int ascii = (int)(s[i]);
        if(ascii >= 48 && ascii <= 57) { // digit
            val.push(ascii-48); 
        }
        else { // s[i] is +,-,*,/
            // work
            int val1 = val.top();
            val.pop();
            int val2 = val.top();
            val.pop();
            int ans = solve(val1,val2,s[i]);
            val.push(ans);
        }
    }
    cout<<val.top()<<endl; // 5
    cout<<(7+9)*4/8-3<<endl; // 5
    return 0;
}