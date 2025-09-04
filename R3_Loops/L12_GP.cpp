#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter no of terms : ";
    cin>>n;
    // 3,12,48,---,n terms
    // a -> first term
    // r -> common ratio
    int a = 3;
    int r = 4;
    for(int i = 1 ; i <= n ; i++) {
        cout<<a<<" ";
        a *= r;
    }
    return 0;
}

// Enter no of terms : 10
// 3 12 48 192 768 3072 12288 49152 196608 786432 