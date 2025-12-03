#include <iostream>
using namespace std;

void gun() {
    cout<<"Hello CW"<<endl;
    return;
}

void fun() {
    cout<<"Hello PW"<<endl;
    // function call
    gun();
    return;
}

int main()
{
    // function call
    fun();
    return 0;
}

// Hello PW
// Hello CW

// call stack :

// gun()
// fun()
// main()