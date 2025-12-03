#include <iostream>
using namespace std;

void fun() {
    cout<<"Hello PW"<<endl;
    // function calling itself
    fun();
    return;
}

int main()
{
    fun();
    return 0;
}

// results in infinite loop