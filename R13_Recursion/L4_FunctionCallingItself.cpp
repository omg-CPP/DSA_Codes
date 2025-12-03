#include <iostream>
using namespace std;

void fun(int n) {
    if(n == 0) {
        return;
    }
    cout<<"Hello PW"<<endl;
    // function calling itself
    fun(n-1);
    return;
}

int main()
{
    // function call in main function
    fun(3);
    return 0;
}

// Hello PW
// Hello PW
// Hello PW