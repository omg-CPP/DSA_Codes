#include <iostream>
using namespace std;
int aPowerb(int a, int b) {
    if(b == 0) {
        return 1;
    }
    int p = a * aPowerb(a,b-1);
    return p;
}

int main()
{
    int a,b;
    cout<<"Enter base : ";
    cin>>a;
    cout<<"Enter power : ";
    cin>>b;
    int power = aPowerb(a,b);
    cout<<a<<" To the power "<<b<<" is : "<<power<<endl;
    return 0;
}

// Enter base : 3
// Enter power : 4
// 3 To the power 4 is : 81

// Enter base : 2
// Enter power : 10
// 2 To the power 10 is : 1024