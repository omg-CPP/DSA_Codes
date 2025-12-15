#include <iostream>
#include <vector>
using namespace std;

// Leetcode 78
// Subsets
// {1,2,3} = {{},{1},{2},{3},{1,2},{2,3},{1,3},{1,2,3}} = 2^3

void printAllSubsets(string ans, string original) {
    if(original == "") {
        cout<<ans<<endl;
        return;
    }
    char ch = original[0];
    printAllSubsets(ans+ch,original.substr(1));
    printAllSubsets(ans,original.substr(1));
}

void printAllSubsetsOptimised(string ans, string original, int idx) {
    if(idx == original.size()) {
        cout<<ans<<endl;
        return;
    }
    char ch = original[idx];
    printAllSubsetsOptimised(ans,original,idx+1);
    printAllSubsetsOptimised(ans+ch,original,idx+1);
}

void storeSubset(string ans, string original, int idx, vector<string>& s) {
    if(idx == original.size()) {
        s.push_back(ans);
        return;
    }
    char ch = original[idx];
    storeSubset(ans,original,idx+1,s);
    storeSubset(ans+ch,original,idx+1,s);
}

int main()
{
    string str = "abc";
    printAllSubsets("",str);
    // abc
    // ab
    // ac
    // a
    // bc
    // b
    // c
    // -> empty string

    printAllSubsetsOptimised("",str,0);
    // -> empty string
    // c
    // b
    // bc
    // a
    // ac
    // ab
    // abc

    vector<string> s;
    storeSubset("",str,0,s);
    for(int i = 0 ; i < s.size() ; i++) {
        cout<<s[i]<<" ";
    }
    cout<<endl;
    //  c b bc a ac ab abc 
    return 0;
}