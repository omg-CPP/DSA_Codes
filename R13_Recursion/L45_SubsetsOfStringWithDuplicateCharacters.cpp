#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void storeSubset(string ans, string original, vector<string>& s, bool flag) {
    if(original == "") {
        s.push_back(ans);
        return;
    }
    char ch = original[0];
    if(original.length() == 1) {
        if(flag == true) {
            // left call
            storeSubset(ans+ch,original.substr(1),s,true);
        }
        // right call
        storeSubset(ans,original.substr(1),s,true);
        return;
    }

    char dh = original[1];
    if(ch == dh) { // duplicate
        if(flag == true) {
            // left call
            storeSubset(ans+ch,original.substr(1),s,true);
        }
        // right call
        storeSubset(ans,original.substr(1),s,false);
    }
    else { // no duplicate
        if(flag == true) {
            // left call
            storeSubset(ans+ch,original.substr(1),s,true);
        }
        // right call
        storeSubset(ans,original.substr(1),s,true);
    }
}

int main()
{
    string str = "aba";
    sort(str.begin(),str.end()); // sort the string
    vector<string> s;
    storeSubset("",str,s,true);
    for(int i = 0 ; i < s.size() ; i++) {
        cout<<s[i]<<" ";
    }
    // "" d c cd b bd bc bcd a ad ac acd ab abd abc abcd 
    // abcd abc abd ab acd ac ad a bcd bc bd b cd c d ""
    cout<<endl;
    return 0;
}

// ""
// d
// c
// cd
// b
// bd
// bc
// bcd
// a
// ad
// ac
// acd
// ab
// abd
// abc
// abcd