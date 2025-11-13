#include <iostream>
#include <vector>
using namespace std;

void funBruteForce(string s) {
    int maxi = 0;
    int len = s.length();
    for(int i = 0 ; i < len ; i++) {
        int count = 1;
        for(int j = i+1 ; j < len ; j++) {
            if(s[j] == s[i]) {
                count++;
            }
        }
        if(maxi < count) {
            maxi = count;
        }
    }

    for(int i = 0 ; i < len ; i++) {
        char ch = s[i];
        int count = 1;
        for(int j = i+1 ; j < len ; j++) {
            if(s[j] == s[i]) {
                count++;
            }
        }
        if(count == maxi) {
            cout<<ch<<" "<<maxi<<endl;
        }
    }
}

void funOptimal(string s) {
    int len = s.length();
    vector<int> arr(26,0);
    for(int i = 0 ; i < len ; i++) {
        char ch = s[i];
        int ascii = (int)ch;
        // a -> 0 => 97 - 97 = 0
        arr[ascii-97]++;
    }

    int maxi = 0;
    for(int i = 0 ; i < 26 ; i++) {
        if(arr[i] > maxi) {
            maxi = arr[i];
        }
    }

    for(int i = 0 ; i < 26 ; i++) {
        if(arr[i] == maxi) {
            int ascii = i + 97;
            char ch = (char)ascii;
            cout<<ch<<" "<<maxi<<endl;
        }
    }
}

int main()
{
    // highest frequency character
    string s = "physicswallah";
    string t = "leetcode";
    funBruteForce(s);
    funOptimal(s);
    funOptimal(t);
    return 0;
}

// h 2
// s 2
// a 2
// l 2

// a 2
// h 2
// l 2
// s 2

// e 3