#include <iostream>
using namespace std;

void printNTo1(int n) {
    // base case : terminating statement
    if(n == 0) {
        return;
    }
    // work
    cout<<n<<endl;
    // recursive call : smaller sub-problem
    printNTo1(n-1);
    return;
}

int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    printNTo1(n);
    return 0;
}

// Enter n : 5
// 5
// 4
// 3
// 2
// 1