#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

string removeDuplicates(string s) {
    stack<char> st;
    st.push(s[0]);
    for(int i = 1 ; i < s.size() ; i++) {
        if(s[i] != st.top()) {
            st.push(s[i]);
        }
    }
    string str = "";
    while(st.size() > 0) {
        str = str + st.top();
        st.pop();
    }
    reverse(str.begin(), str.end());
    return str;
}

int main()
{
    string s = "aaabbcddaabffg";
    cout<<s<<endl; // aaabbcddaabffg
    s = removeDuplicates(s);
    cout<<s<<endl; // abcdabfg
    return 0;
}