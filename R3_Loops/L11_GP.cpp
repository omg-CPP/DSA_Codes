#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cout<<"Enter no of terms : ";
    cin>>n;
    // 1,2,4,8,32,----,n terms
    // a -> first term
    // r -> common ratio
    // An = a*r^(n-1) = 1*2^(n-1) = 2^(n-1)
    for(int i = 1 ; i <= pow(2,n-1) ; i *= 2) {
        cout<<i<<" ";
    }
    return 0;
}

// Enter no of terms : 10
// 1 2 4 8 16 32 64 128 256 512 