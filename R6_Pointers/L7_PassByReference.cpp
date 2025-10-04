#include <iostream>
using namespace std;

void swap(int* x, int* y) {
    // int* x = &a => *x = a
    // int* y = &b => *y = b
    
    int temp = *x; // temp = a
    *x = *y; // a = b
    *y = temp; // b = a
    return;
}
int main()
{
    int a, b;
    cout<<"Enter a : ";
    cin>>a;
    cout<<"Enter b : ";
    cin>>b;

    int* x = &a;
    int* y = &b;
    cout<<a<<" "<<b<<endl;
    swap(x,y);
    cout<<a<<" "<<b<<endl;
    return 0;
}

// Enter a : 5
// Enter b : 7
// 5 7
// 7 5

// Enter a : 23
// Enter b : 59
// 23 59
// 59 23