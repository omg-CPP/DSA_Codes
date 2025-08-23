#include <iostream>
using namespace std;
int main()
{
    double p,r,t;
    cout<<"Enter principle : ";
    cin>>p;
    cout<<"Enter rate : ";
    cin>>r;
    cout<<"Enter time : ";
    cin>>t;
    double SI = (p*r*t)/100;
    cout<<"The  Simple Interest is : "<<SI<<endl;
    return 0;
}

// Enter principle : 500
// Enter rate : 2.5
// Enter time : 5
// The  Simple Interest is : 62.5