#include <iostream>
using namespace std;
int main()
{
    int a;
    cout<<"Enter base : ";
    cin>>a;
    int b;
    cout<<"Enter power : ";
    cin>>b;
    int power = 1;
    for(int i = 1 ; i <= b ; i++) {
        power = power * a;
    }
    cout<<a<<" raised to the power "<<b<<" is : "<<power<<endl;
    return 0;
}

// Enter base : 3
// Enter power : 5
// 3 raised to the power 5 is : 243

// Enter base : 2
// Enter power : 5
// 2 raised to the power 5 is : 32