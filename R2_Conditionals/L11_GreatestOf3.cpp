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

    if(a >= b && a >= c) {
        cout<<"a is greatest"<<endl;
    }
    else if(b >= a && b >= c) {
        cout<<"b is greatest"<<endl;
    }
    else { 
        cout<<"c is greatest"<<endl;
    }
    return 0;
}

// Enter a : 5
// Enter b : 5
// Enter c : 7
// c is greatest