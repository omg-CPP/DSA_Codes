#include <iostream>
using namespace std;
int main()
{
    int x = 9;
    bool z = x < 10;
    cout<<z<<endl; // 1

    // char and bool are compatible
    int i = 65;
    char j = 'A';
    if(i == j) { // WOW
        cout<<"WOW"<<endl;
    }
    else {
        cout<<"MOM"<<endl;
    }

    // int and bool are compatible
    int k = 0;
    bool l = false;
    cout<<l<<endl; // 0
    if(k == l) {
        cout<<"Hello"<<endl; // Hello
    }
    else {
        cout<<"Jello"<<endl;
    }

    bool flag = true;
    cout<<flag<<endl; // 1
    return 0;
}