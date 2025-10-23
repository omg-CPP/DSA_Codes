// Leetcode : 2749

// You are given two integers num1 and num2.

// In one operation, you can choose integer i in the range [0, 60] and subtract 2i + num2 from num1.

// Return the integer denoting the minimum number of operations needed to make num1 equal to 0.

// If it is impossible to make num1 equal to 0, return -1.

#include <iostream>
#include <vector>
using namespace std;

int makeTheIntegerZero(int num1, int num2) {
    int t = 1;
    while(true) {
        long long val = (long long)num1 - (long long)t * num2;
        if(val < 0) {
            return -1;
        }
        if(__builtin_popcountll(val) <= t && t <= val) {
            return t;
        }
        t++;
    }
    return -1;
}

int main()
{
    int num1 = 3;
    int num2 = -2;
    cout << makeTheIntegerZero(num1, num2) << endl; // Output: 3
    return 0;
}