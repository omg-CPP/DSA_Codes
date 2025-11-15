#include <iostream>
#include <vector>
using namespace std;

// A substring is a contiguous (non-empty) sequence of characters within a string.

// A vowel substring is a substring that only consists of vowels ('a', 'e', 'i', 'o', and 'u') and has all five vowels present in it.

// Given a string word, return the number of vowel substrings in word.

bool checkAllVowels(vector<int>& v) {
    for(int i = 0 ; i < v.size() ; i++) {
        // checking if a single vowel is missing
        if(v[i] == 0) {
            return false;
        }
    }
    return true;
}

int countVowelSubstrings(string word) {
    int n = word.length();
    int count = 0;
    for(int i = 0 ; i < n ; i++) {
        vector<int> v(5,0);
        for(int j = i ; j < n ; j++) {
            if(word[j] == 'a') v[0]++;
            else if(word[j] == 'e') v[1]++;
            else if(word[j] == 'i') v[2]++;
            else if(word[j] == 'o') v[3]++;
            else if(word[j] == 'u') v[4]++;
            else break;
            // function to check if all 5 vowels are present or not
            if(checkAllVowels(v) == true) {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    string s = "aeiouu";
    cout<<countVowelSubstrings(s)<<endl; // 2
    string t = "cuaieuouac";
    cout<<countVowelSubstrings(t)<<endl; // 7
    string str = "abjkoe";
    cout<<countVowelSubstrings(str)<<endl; // 0
    return 0;
}