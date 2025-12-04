#include <iostream>
using namespace std;

void print(int n) {
    // base case : terminating statement
    if(n == 0) {
        return;
    }
    // work before call
    cout<<n<<endl;
    // recursive call
    print(n-1);
    // work after call

    // to avoid double printing of number 1
    if(n == 1) {
        return;
    }
    cout<<n<<endl;
    return;
}

int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    print(n);
    return 0;
}

// Enter n : 5
// 5
// 4
// 3
// 2
// 1
// 2
// 3
// 4
// 5