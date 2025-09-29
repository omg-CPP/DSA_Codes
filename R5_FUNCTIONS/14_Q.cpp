#include <iostream>
using namespace std;

void function(int a, int b) {
    cout<<a<<" "<<b<<endl;
}

void function(int a, int b, int c) {
    cout<<a<<" "<<b<<" "<<c<<endl;
}

void function(double a, double b) {
    cout<<a<<" "<<b<<endl;
}

void function(int a, double b) {
    cout<<a<<" "<<b<<endl;
}

int main()
{
    function(4,6); // 4 6
    function(4,6,8); // 4 6 8
    function(3.3,5.6); // 3.3 5.6
    function(4,8.3); // 4 8.3
    return 0;
}