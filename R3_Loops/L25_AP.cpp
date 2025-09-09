#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter no of terms : ";
    cin>>n;
    // AP : 100,97,94,91,----,upto last positives
    int a = 100;
    int d = -3;
    for(int i = 1 ; a > 0 ; i++) {
        cout<<a<<" ";
        a += d;
    }
    return 0;
}

// Enter no of terms : 34
// 100 97 94 91 88 85 82 79 76 73 70 67 64 61 58 55 52 49 46 43 40 37 34 31 28 25 22 19 16 13 10 7 4 1 
