// Remove all occurences of 'a' from a string.
#include <iostream>
#include <string>
using namespace std;

void removeChar(string ans, string original) {
    if(original.size() == 0) {
        cout<<ans<<endl;
        return;
    }
    char ch = original[0];
    if(ch == 'a') {
        removeChar(ans,original.substr(1));
    }
    else {
        removeChar(ans+ch,original.substr(1));
    }
}

void removeCharOptimised(string ans, string original, int idx) {
    if(idx == original.size()) {
        cout<<ans<<endl;
        return;
    }
    char ch = original[idx];
    if(ch == 'a') {
        removeCharOptimised(ans,original,idx+1);
    }
    else {
        removeCharOptimised(ans+ch,original,idx+1);
    }
}

int main()
{
    string str = "Raghav Garg";
    cout<<str.length()<<" "<<str.size()<<endl; // 11 11
    string s = "";
    for(int i = 0 ; i < str.size() ; i++) {
        if(str[i] != 'a') {
            s = s + str[i];
        }
    }

    cout<<s<<endl; // Rghv Grg
    for(int i = 0 ; i < s.size() ; i++) {
        cout<<s[i];
    }
    // Rghv Grg
    cout<<endl;

    removeChar("",str); // Rghv Grg

    cout<<endl;

    removeCharOptimised("",str,0); // Rghv Grg
    return 0;
}