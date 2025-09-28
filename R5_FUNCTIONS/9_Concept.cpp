// To see that arguments in main() and fun() both are different, only their name is same.
#include <iostream>
using namespace std;
int a = 9; // global variable => all fun can access

void fun(int x, int y) {
    // formal parameters
    cout<<"Address of fun() x : "<<&x<<endl; // Address of fun() x : 0x61fef0
    cout<<"Address of fun() y : "<<&y<<endl; // Address of fun() y : 0x61fef4
}

void f() {
    // cout<<a; // error -> Scope of variable
    cout<<a<<endl;
}

// default value of arguments
void func(int x = 7, int y = 8) {
    cout<<x<<" "<<y<<endl;
}

void funct(int x = 8, bool flag = true) {
    cout<<x<<" "<<flag<<endl;
}

int main()
{
    int x = 3;
    int y = 7;
    cout<<x<<endl; // 3
    cout<<y<<endl; // 7
    cout<<"Address of main() x : "<<&x<<endl; // Address of main() x : 0x61ff0c
    cout<<"Address of main() y : "<<&y<<endl; // Address of main() y : 0x61ff08
    fun(x,y);
    // actual parameters
    cout<<a<<endl; // 9 : global
    int a = 4; // local variable : only accessed by fun in which it is present
    cout<<a<<endl; // 4
    f(); // 9

    func(); // 7 8
    func(4,6); // 4 6
    func(4); // 4 8

    funct(false); // 0 1
    return 0;
}