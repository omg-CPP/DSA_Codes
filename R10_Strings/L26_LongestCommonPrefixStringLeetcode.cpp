#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
    int n = strs.size();
    if(n == 1) {
        return strs[0];
    }
    sort(strs.begin(),strs.end());
    string first = strs[0];
    string last = strs[n-1];
    string s = "";
    for(int i = 0 ; i < min(first.length(),last.length()) ; i++) {
        if(first[i] == last[i]) {
            s = s + first[i];
        }
        else {
            return s;
        }
    }
    return s;
}
int main()
{
    vector<string> strs = {"flower","flow","flight"};
    for(int i = 0 ; i < strs.size() ; i++) {
        cout<<strs[i]<<" "<<endl;
    }
    // flower 
    // flow 
    // flight 
    cout<<endl;
    sort(strs.begin(),strs.end());
    for(int i = 0 ; i < strs.size() ; i++) {
        cout<<strs[i]<<" "<<endl;
    }
    // flight 
    // flow 
    // flower 

    vector<string> v = {"dog","racecar","car"};
    cout<<longestCommonPrefix(strs)<<endl; // fl
    cout<<longestCommonPrefix(v)<<endl; // "" -> empty string
    cout<<endl;
    return 0;
}