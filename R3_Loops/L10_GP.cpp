#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter no of terms : ";
    cin>>n;
    // 1,2,4,8,32,----,n terms
    // a -> first term
    // r -> common ratio
    int a = 1;
    int r = 2;
    for(int i = 1 ; i <= n ; i++) {
        cout<<a<<" ";
        a *= r;
    }
    return 0;
}

// Enter no of terms : 10
// 1 2 4 8 16 32 64 128 256 512 