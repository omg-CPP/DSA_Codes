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

    if((a+b > c) && (b+c > a) && (a+c > b)) {
        cout<<"Valid Triangle"<<endl;
    }
    else {
        cout<<"Invalid Triangle"<<endl;
    }
    return 0;
}

// Enter a : 3 
// Enter b : 4
// Enter c : 5
// Valid Triangle