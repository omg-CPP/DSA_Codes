#include <iostream>
using namespace std;
int main()
{
    string str = "123456";
    int x = stoi(str);
    cout<<x<<endl; // 123456
    
    int a = 1234567;
    string s = to_string(a);
    cout<<s<<endl; // "1234567"

    string st = "1234567891021";
    long long l = stoll(st);
    cout<<l<<endl; // 1234567891021
    return 0;
}