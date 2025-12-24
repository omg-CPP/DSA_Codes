#include <iostream>
using namespace std;

string countAndSay(int n) {
    if(n == 1) {
        return "1";
    }
    string str = countAndSay(n-1);
    // str = 3322251 -> 23321511
    string ztr = "";
    int freq = 1;
    char ch = str[0];
    for(int i = 1 ; i < str.size() ; i++) {
        char dh = str[i];
        if(ch == dh) {
            freq++;
        }
        else { // ch != dh
            ztr = ztr + (to_string(freq) + ch);
            freq = 1;
            ch = dh;
        }
    }
    ztr = ztr + (to_string(freq) + ch);
    return ztr;
}

int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    string s = countAndSay(n);
    cout<<s<<endl;
    return 0;
}

// Enter n : 4
// 1211

// Enter n : 8
// 1113213211