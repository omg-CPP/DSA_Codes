#include <iostream>
using namespace std;
int main()
{
    // a > 0 and b > 0 and a > b
    int a = 10;
    int b = 3;
    int r;
    int q = a/b;
    // Dividend = Quotient*Divisor + Remainder
    // Remainder = Dividend - Quotient*Divisor
    // Quotient = a/b
    // r = a - (q*b)
    r = a - (q*b);
    // r = a - ((a/b)*b)
    cout<<"The Remainder is : "<<r<<endl;
    // The Remainder is : 1  
    return 0;
}