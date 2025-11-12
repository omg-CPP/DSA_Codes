#include <iostream>
using namespace std;
int main()
{
    int x = 12345678;
    string s = to_string(x);
    cout<<s.length()<<endl; // 8
    return 0;
}