// `U Given a positive integer, return true if it is a power of 2 using recursion.

#include <iostream>
using namespace std;

bool isPowerOf2(int n) {
    // base case : 2^0 = 1
    if(n == 1) {
        return true;
    }
    if(n % 2 != 0 || n <= 0) {
        return false;
    }
    // recursive step
    return isPowerOf2(n/2);
}

int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    if(isPowerOf2(n) == true) {
        cout<<n<<" is a power of 2";
    }
    else {
        cout<<n<<" is NOT a power of 2";
    }
    return 0;
}

// 16 : 16 → 8 → 4 → 2 → 1 ✔️

// 18 → 18 mod 2 == 0 → 9 mod 2 ≠ 0 ❌

// Enter n : 16
// 16 is a power of 2

// Enter n : 56
// 56 is NOT a power of 2
