#include <iostream>
using namespace std;
int main()
{
    float radius;
    cout<<"Enter radius : ";
    cin>>radius;
    float pi = 3.1415;
    float area = pi*radius*radius;
    cout<<"The radius of the circle is : "<<area<<endl;
    return 0;
}

// Enter radius : 5
// The radius of the circle is : 78.5375