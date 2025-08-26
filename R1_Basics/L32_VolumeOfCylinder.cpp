#include <iostream>
using namespace std;
int main()
{
    float pi = 3.1415;
    float r,h,V;
    cout<<"Enter Radius : ";
    cin>>r;
    cout<<"Enter Height : ";
    cin>>h;
    V = pi*r*r*h;
    cout<<"The Volume of Sphere is : "<<V<<endl;
    return 0;
}

// Enter Radius : 5
// Enter Height : 10
// The Volume of Sphere is : 785.375