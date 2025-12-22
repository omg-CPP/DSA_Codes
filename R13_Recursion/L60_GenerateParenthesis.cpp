#include <iostream>
#include <vector>
using namespace std;

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]
 
void generate(string str, vector<string>& s, int open, int close, int n) {
    if(close == n) {
        s.push_back(str);
        return;
    }
    if(open < n) {
        generate(str+'(',s,open+1,close,n);
    }
    if(close < open) {
        generate(str+')',s,open,close+1,n);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> s;
    generate("",s,0,0,n);
    return s;
}

int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    vector<string> s = generateParenthesis(n);
    for(int i = 0 ; i < s.size() ; i++) {
        cout<<s[i]<<" ";
    }
    cout<<endl;

    string str = "abc";
    cout<<str<<endl; // abc
    cout<<str+'d'<<endl; // abcd
    cout<<str<<endl; // abc
    str = str + 'd'; 
    cout<<str<<endl; // abcd
    return 0;
}

// Enter n : 2
// (()) ()() 

// Enter n : 3
// ((())) (()()) (())() ()(()) ()()() 