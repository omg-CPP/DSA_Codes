#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter no of terms : ";
    cin>>n;
    // 4,7,10,13,16,---
    int a = 4;
    int d = 3;
    for(int i = 1 ; i <= n ; i++) {
        cout<<a<<" ";
        a += d;
    }
    return 0;
}

// Enter no of terms : 12
// 4 7 10 13 16 19 22 25 28 31 34 37 