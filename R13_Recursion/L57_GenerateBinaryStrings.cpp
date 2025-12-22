#include <iostream>
using namespace std;

void generate(string s, int n) {
    if(s.size() == n) {
        cout<<s<<endl;
        return;
    }
    generate(s+"0",n);
    generate(s+"1",n);
}

void generateBinaryStrings(string s, int n) {
    if(s.size() == n) {
        cout<<s<<endl;
        return;
    }
    if(s == "") {
        generateBinaryStrings(s+"0",n);
        generateBinaryStrings(s+"1",n);
    }
    else if(s[s.size()-1] == '0') {
        generateBinaryStrings(s+"0",n);
        generateBinaryStrings(s+"1",n);
    }
    else if(s[s.size()-1] == '1') {
        generateBinaryStrings(s+"0",n);
    }
}

int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    generate("",n);
    cout<<endl<<"-----------"<<endl;
    generateBinaryStrings("",n);
    return 0;
}

// Enter n : 3
// 000
// 001
// 010
// 011
// 100
// 101
// 110
// 111

// Enter n : 3
// 000
// 001
// 010
// 011
// 100
// 101
// 110
// 111

// -----------
// 000
// 001
// 010
// 100
// 101


// Enter n : 4
// 0000
// 0001
// 0010
// 0011
// 0100
// 0101
// 0110
// 0111
// 1000
// 1001
// 1010
// 1011
// 1100
// 1101
// 1110
// 1111

// -----------
// 0000
// 0001
// 0010
// 0100
// 0101
// 1000
// 1001
// 1010