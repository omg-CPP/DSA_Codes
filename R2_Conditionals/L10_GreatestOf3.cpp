#include <iostream>
using namespace std;
int main()
{
    int a,b,c;
    cout<<"Enter a : ";
    cin>>a;
    cout<<"Enter b : ";
    cin>>b;
    cout<<"Enter c : ";
    cin>>c;

    if(a > b) {
        if(a > c) {
            cout<<a<<" is greatest"<<endl;
        }
        else { // a < c
            cout<<c<<" is greatest"<<endl;
        }
    }
    else { // b > a
        if(b > c) {
            cout<<b<<" is greatest"<<endl;
        }
        else { // b < c
            cout<<c<<" is greatest"<<endl;
        }
    }
    return 0;
}

// Enter a : 5
// Enter b : 8
// Enter c : 9
// 9 is greatest