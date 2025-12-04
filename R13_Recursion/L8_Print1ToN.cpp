#include <iostream>
using namespace std;

// using an extra parameter
void print1ToN(int x, int n) {
    // base case : terminating statement
    if(x > n) {
        return;
    }
    // work
    cout<<x<<endl;
    // recursive call : smaller sub-problem
    print1ToN(x+1,n);
    return;
}

int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    print1ToN(1,n);
    return 0;
}

// Enter n : 5
// 1
// 2
// 3
// 4
// 5