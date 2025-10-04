#include <iostream>
using namespace std;

void swap(int &a, int &b) { // sasta pass by reference
    int temp = a;
    a = b;
    b = temp;
    return;
}
int main()
{
    int a, b;
    cout<<"Enter a : ";
    cin>>a;
    cout<<"Enter b : ";
    cin>>b;

    cout<<a<<" "<<b<<endl;
    swap(a,b);
    cout<<a<<" "<<b<<endl;
    return 0;
}

// Enter a : 5
// Enter b : 7
// 5 7
// 7 5