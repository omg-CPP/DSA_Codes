#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string str = "raghav";
    // \0 is not included in size
    cout<<str.size()<<endl; // 6
    cout<<str.length()<<endl; // 6
    // indexing : 0 to str.length()-1

    string str2 = "abcd";
    cout<<str2<<endl; // abcd
    str2.push_back('e');
    str2.push_back('f');
    str2.push_back('g');
    cout<<str2<<endl; // abcdefg

    str2.pop_back();
    cout<<str2<<endl; // abcdef

    // appends only string using '+'
    string a = "abc";
    cout<<a<<endl; // abc
    string b = "def";
    a = a + b;
    cout<<a<<endl; // abcdef
    a = a + "xyz";
    cout<<a<<endl; // abcdefxyz
    a = "xyz" + a;
    cout<<a<<endl; // xyzabcdefxyz

    // reverse
    string st = "abcdef"; // index : 0 1 2 3 4 5 
    cout<<st<<endl; // abcdef
    reverse(st.begin(),st.end());
    cout<<st<<endl; // fedcba

    string c = "abcdef";
    cout<<c<<endl; // abcdef
    // reverse c to f
    reverse(c.begin()+2,c.end());
    cout<<c<<endl; // abfedc

    string d = "abcdef";
    cout<<d<<endl; // abcdef
    reverse(d.begin()+2,d.end()-1);
    cout<<d<<endl; // abedcf

    // when two index are given
    // reverse index 2 to 4
    // give index from +2 to +5
    string e = "abcdef";
    cout<<e<<endl; // abcdef
    reverse(e.begin()+2,e.begin()+5);
    cout<<e<<endl; // abedcf

    // to_string sunction
    int x = 12345;
    string f = to_string(x);
    cout<<f<<endl; // 12345
    return 0;
}