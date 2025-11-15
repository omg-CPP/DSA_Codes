#include <iostream>
#include <vector>
using namespace std;
// leetcode 205
bool isIsomorphic(string s, string t) {
    if(s.length() != t.length()) {
        return false;
    }
    // checking string s perspective
    vector<int> v(150,1000);
    for(int i = 0 ; i < s.length() ; i++) {
        int idx = (int)s[i];
        if(v[idx] == 1000) {
            v[idx] = s[i] - t[i];
        }
        else if(v[idx] != (s[i] - t[i])) {
            return false;
        }
    }
    // checking string t perspective
    // emptying the vector
    for(int i = 0 ; i < 150 ; i++) {
        v[i] = 1000;
    }
    for(int i = 0 ; i < t.length() ; i++) {
        int idx = (int)t[i];
        if(v[idx] == 1000) {
            v[idx] = t[i] - s[i];
        }
        else if(v[idx] != (t[i] - s[i])) {
            return false;
        }
    }
    return true;
}

int main()
{
    return 0;
}