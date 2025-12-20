#include <iostream>
#include <string>
using namespace std;
// Finding all permutations of a string given all elements are unique.

// Permutations String Brute Force

void permutations(string ans, string original) {
    if(original == "") {
        cout<<ans<<endl;
        return;
    }
    for(int i = 0 ; i < original.size() ; i++) {
        char ch = original[i];
        string left = original.substr(0,i);
        string right = original.substr(i+1);
        permutations(ans+ch,left+right);
    }
}
int main()
{
    string str = "abc";
    permutations("",str);

    // string str = "abcde";
    // cout<<str.substr(0,1)<<endl; // a
    // cout<<str.substr(1,2)<<endl; // bc
    // cout<<str.substr(0,3)<<endl; // abc
    // cout<<str.substr(1,3)<<endl; // bcd
    // cout<<str.substr(2,3)<<endl; // cde
    // (a,b) : a -> starting index inclusive, b : how much length

    // c ko hata ke 
    // string left = str.substr(0,2);
    // cout<<left<<endl; // ab
    // string right = str.substr(2+1);
    // cout<<right<<endl; // de
    return 0;
}

// abc
// acb
// bac
// bca
// cab
// cba