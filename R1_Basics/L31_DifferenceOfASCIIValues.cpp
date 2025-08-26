#include <iostream>
using namespace std;
int main()
{
    char ch1;
    cout<<"Enter first character : ";
    cin>>ch1;
    char ch2;
    cout<<"Enter second character : ";
    cin>>ch2;
    int x = (int)ch1;
    int y = (int)ch2;
    cout<<ch1<<"-"<<ch2<<":"<<x-y<<endl;
    return 0;
}

// Enter first character : a
// Enter second character : b
// a-b:-1

// Enter first character : A
// Enter second character : D
// A-D:-3