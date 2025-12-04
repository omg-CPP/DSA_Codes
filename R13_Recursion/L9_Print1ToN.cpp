#include <iostream>
using namespace std;

// without using an extra parameter
// print(work) after call
void print1ToN(int n) {
    // base case : terminating statement
    if(n == 0) {
        return;
    }
    // recursive call : smaller sub-problem
    print1ToN(n-1);
    // work
    cout<<n<<endl;
    return;
}

int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    print1ToN(n);
    return 0;
}

// Enter n : 5
// 1
// 2
// 3
// 4
// 5