#include <iostream>
using namespace std;

// Time Complexity : O(min(a,b))
int gcd(int a, int b) {
    int mini = min(a,b);
    for(int i = mini ; i >= 1 ; i--) {
        if(a % i == 0 && b % i == 0) {
            return i;
        }
    }
    return 1;
}

// T.C. = O(log(a+b))
int recGcd(int a, int b) {
    // Euclid's Algorithm
    // Long Division Method to find GCD
    if(a < b) {
        // base case
        if(a == 0) {
            return b;
        }
        return recGcd(b%a,a);
    }
    else { // a > b
        // base case
        if(b == 0) {
            return a;
        }
        return recGcd(a%b,b);
    }
}

int main()
{
    int a = 24;
    int b = 60;
    cout<<gcd(a,b)<<endl; // 12
    cout<<recGcd(a,b)<<endl; // 12
    cout<<recGcd(27,45)<<endl; // 9
    return 0;
}