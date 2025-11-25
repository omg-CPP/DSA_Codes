// Leetcode 50 :: Pow(x,n) 
// -2^31 <= n <= 2^31-1
// for a code to get submit :: 10^8 operations
// as 10^8  <<<  2^31
// Time Limit Exceeded

#include <iostream>
using namespace std;

// TLE Solution : O(n)
// eg - 2^3 = 2 * 2 * 2
// The issue with your code is that when n is -2^31 (-2147483648), the line n = -n causes integer overflow because the maximum positive int value is 2^31-1 (2147483647).
// Run Time Error
double myPowNaive(double x, int n) {
    double ans = 1;
    // let say = n : -2
    if(n < 0) {
        x = 1/x;
        n = -n;
    }
    for(int i = 1 ; i <= n ; i++) {
        ans = ans * x;
    }
    return ans;
}

// Binary Exponentiation : Optimal Approach
// If n is a decimal number, than it's binary form will have log2(n) + 1 Digits
// eg : n = 8 :: binary = 1000 : 4 digits = log2(8) + 1 Digits
// T.C. ===> O(n) -> O(logn)
// 1000 = (1 * 2^3) + (0 * 2^2) + (0 * 2^1) + (0 * 2^0) = 8

// eg we need to calculate :: 3^5 = 243
// so instead of doing 3*3*3*3*3
// So, 5 = 101 => (1 * 3^4) * (0 * 3^2) * (1 * 3^1) = 243

// 2 5 1
// 2 2 0
// 2 1 1
//   0

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
    long binaryForm = n; // -2^31 <= n <= 2^31-1
    // To handle -ve value of n
    if(n < 0) {
        x = 1/x;
        binaryForm = -binaryForm;
    }

    double ans = 1;
    // Time Complexity : O(logn + 1) = O(log2(n))
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