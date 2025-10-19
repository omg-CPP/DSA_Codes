#include <iostream>
using namespace std;

double myPow(double x, int n) {
    // Corner Cases : Constant Operations
    if(n == 0) {
        return 1.0;
    }
    if(x == 0) {
        return 0.0;
    }
    if(x == 1) {
        return 1.0;
    }
    if(x == -1 && n % 2 == 0) {
        return 1.0;
    }
    if(x == -1 && n % 2 != 0) {
        return -1.0;
    }

    // Binary Exponentiation
    long binaryForm = n;
    // To handle -ve value of n
    if(n < 0) {
        x = 1/x;
        binaryForm = -binaryForm;
    }
    double ans = 1;
    // Time Complexity : O(logn)
    while(binaryForm > 0) {
        if(binaryForm % 2 == 1) { // last digit = 1
            ans = ans * x;
        }
        x = x * x;
        binaryForm = binaryForm / 2;
    }
    return ans;
}

int main()
{
    double x = 3;
    int n = 5;
    int ans = myPow(x,n);
    cout<<ans<<endl; // 243
    cout<<myPow(2,10)<<endl; // 1024
    return 0;
}