#include <iostream>
using namespace std;
int main()
{
    // In C++, Strings are mutable
    string str = "raghav";
    cout<<str<<endl; // raghav
    str[1] = 'o';
    cout<<str<<endl; // roghav
    return 0;
}