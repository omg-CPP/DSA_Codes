#include <iostream>
using namespace std;

int factorial(int n) {
    // base case
    if(n == 0 || n == 1) {
        return 1;
    }
    // recursive call
    int ans = n * factorial(n-1);
    return ans;
}

int main()
{
    int num;
    cout<<"Enter the number : ";
    cin>>num;
    int ans = factorial(num);
    cout<<ans<<endl;
    return 0;
}

// Enter the number : 6
// 720

// Enter the number : 4
// 24

// Enter the number : 0
// 1