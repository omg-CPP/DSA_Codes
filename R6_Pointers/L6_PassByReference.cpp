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

    cout<<a<<" "<<b<<endl;
    swap(&a,&b);
    cout<<a<<" "<<b<<endl;
    return 0;
}

// Enter a : 5
// Enter b : 7
// 5 7
// 7 5