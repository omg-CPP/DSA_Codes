#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
    int hcf = 1; // for co-prime numbers
    for(int i = 1 ; i <= min(a,b) ; i++) {
        if((a % i == 0) && (b % i == 0)) {
            hcf = i; // i is a common factor
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

// Enter first number : 12
// Enter second number : 18
// 6