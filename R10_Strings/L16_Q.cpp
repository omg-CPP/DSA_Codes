// Input a string of length less than 10 and convert it into integer without using builtin function.
#include <iostream>
using namespace std;
int main()
{
    string str;
    cout<<"Enter string : ";
    getline(cin,str);
    cout<<str<<endl;
    // int x = stoi(str); // in-built function to convert string to int
    // cout<<x<<endl;
    // cout<<str.back();
    // char ch = '0';
    // cout<<(int)ch<<endl; // 48
    // cout<<('4'-'0')<<endl;
    // cout<<('A'-'B')<<endl; // -1
    int val = 0;
    int fac = 1;
    while(str.size() != 0) {
        val = val + (fac * ((int)str.back() - (int)'0'));
        str.pop_back();
        fac = fac * 10;
    }
    cout<<val<<endl;
    return 0;
}

// Enter string : 3244
// 3244
// 3244

// Enter string : 12
// 12
// 12