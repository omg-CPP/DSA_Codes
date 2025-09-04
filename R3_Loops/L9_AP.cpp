#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter no of terms : ";
    cin>>n;
    // 5,1,-3,-11,-15,---
    int a = 5;
    int d = -4;
    for(int i = 1 ; i <= n ; i++) {
        cout<<a<<" ";
        a += d;
    }
    return 0;
}

// Enter no of terms : 10
// 5 1 -3 -7 -11 -15 -19 -23 -27 -31 