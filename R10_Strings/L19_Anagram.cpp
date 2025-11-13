#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
// Leetcode : 242
bool isAnagram(string s, string t) {
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    if(s == t) {
        return true;
    }
    return false;
}

int main()
{
    string s = "physicswallah";
    string t = "phywallahsics";
    if(isAnagram(s,t) == true) {
        cout<<"Anagram"<<endl;
    }
    else {
        cout<<"Not an Anagram"<<endl;
    }
    return 0;
}
// Anagram