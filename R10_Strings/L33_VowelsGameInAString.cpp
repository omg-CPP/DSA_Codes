// leetcode : 3227
// BrainTeaser
#include <iostream>
#include <string>
using namespace std;

// T.C. = O(n) where n is the size of the string s
// S.C. = O(1)

bool doesAliceWin(string s) {
    bool flag = true; // my string contains only consonants
    for(int i = 0 ; i < s.size() ; i++) {
        if(s[i] == 'a' || s[i] == 'e' ||
            s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            // my string contains both vowels and consonants
            flag = false; 
            break;
        }
    }
    if(flag == true) {
        return false;  // Bob Wins : when s contains only consonants
    }
    return true;
}

int main() {
    string s = "leetcode";
    cout<<doesAliceWin(s)<<endl;   // 1 : Alice wins
    string t = "bcddfgh";
    cout<<doesAliceWin(t)<<endl;   // 0 : Bob wins
    return 0;
}


// If my string contains both vowels and consonants then in that case Alice will only win

// case 1 : if even no of vowels : 4
    // alice would remove longest substring containing 3 vowels
    // then bob will have the left part of string with 1 vowel
    // which bob could not remove as he could remove even noofvowels substring
    // so he removes anything with 0 vowels for example a consonant
    // then alice removes complete left part containing 1 vowel and wins the game

// case 2 : if odd no of vowels : 3
    // alice would remove complete string as there are odd noOfVowels


// Bob will only win when string has no vowels and only consonants
    // than due to 0 vowels bob will remove complete string and wins the game
