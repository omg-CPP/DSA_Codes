#include <iostream>
#include <cmath>
using namespace std;

// more optimised as hcf must be at the last
int gcd(int a, int b) {
    int hcf = 1; // for co-prime numbers
    for(int i = min(a,b) ; i >= 1  ; i--) {
        if((a % i == 0) && (b % i == 0)) {
            hcf = i; // i is a common factor
            break;
        }
    }
    return hcf;
}

int main()
{
    int a;
    cout<<"Enter first number : ";
    cin>>a;
    int b;
    cout<<"Enter second number : ";
    cin>>b;
    cout<<gcd(a,b);
    return 0;
}

// Enter first number : 24
// Enter second number : 60
// 12