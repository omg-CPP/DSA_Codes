#include <iostream>
using namespace std;

void greet() {
    cout<<"Good Morning"<<endl;
    cout<<"How are you"<<endl;
}

int product(int a, int b) {
    return a*b;
}

int main()
{
    // function call
    greet();
    // Good Morning
    // How are you
    int x = product(2,4);
    cout<<x<<endl; // 8
    greet();
    // Good Morning
    // How are you
    int a = 6;
    int b = 8;
    cout<<a<<" "<<b<<endl;
    // 6 8
    swap(a,b);
    cout<<a<<" "<<b<<endl;
    // 8 6
    cout<<min(4,2)<<endl; // 2
    cout<<max(4,2)<<endl; // 4
    return 0;
}