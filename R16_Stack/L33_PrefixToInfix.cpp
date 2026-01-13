#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <climits>
#include <cmath>
using namespace std;

// Prefix to Infix

string solve(string val1, string val2, char ch) {
    string s = "";
    s = s + val1;
    s.push_back(ch);
    s = s + val2;
    return s;
}

int main()
{
    string s = "-/*+79483"; 
    // we will need one stacks, one for val
    stack<string> val;

    for(int i = s.size()-1 ; i >= 0 ; i--) { // reverse loop
        // check if s[i] is a digit (0-9) 
        int ascii = (int)(s[i]);
        if(ascii >= 48 && ascii <= 57) { // digit
            val.push(to_string(ascii-48)); 
        }
        else { // s[i] is +,-,*,/
            // work
            string val1 = val.top();
            val.pop();
            string val2 = val.top();
            val.pop();
            string ans = solve(val1,val2,s[i]);
            val.push(ans);
        }
    }
    cout<<val.top()<<endl; // 7+9*4/8-3
    cout<<"(7+9)*4/8-3"<<endl; // (7+9)*4/8-3
    return 0;
}