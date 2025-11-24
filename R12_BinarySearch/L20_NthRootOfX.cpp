// You are given 2 numbers n and m, the task is to find n√m (nth root of m). If the root is not integer then returns -1.

// Input: n = 3, m = 27
// Output: 3
// Explanation: 33 = 27

// Input: n = 3, m = 9
// Output: -1
// Explanation: 3rd root of 9 is not integer.

// Input: n = 4, m = 625
// Output: 5
// Explanation: 54 = 625

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Brute Force
int nthRootNaive(int n, int m) {
    return pow(m,(1.0/n));
}


// Binary Search & Binary Exponentiation
long long evaluate(int mid, int n) {
    // Corner Cases : Constant Operations
    if(n == 0) {
        return 1.0;
    }
    if(mid == 0) {
        return 0.0;
    }
    if(mid == 1) {
        return 1.0;
    }
    if(mid == -1 && n % 2 == 0) {
        return 1.0;
    }
    if(mid == -1 && n % 2 != 0) {
        return -1.0;
    }

    // Binary Exponentiation
    int binaryForm = n;  // 1 <= n <= 30

    long long ans = 1;
    // Time Complexity : O(logn + 1) = O(log2(n))
    while(binaryForm > 0) {
        if(binaryForm % 2 == 1) { // last digit = 1
            ans = ans * mid;
        }
        mid = mid * mid;
        binaryForm = binaryForm / 2;
    }
    return ans;
}


// O(log2(m)) for Binary Search
// O(log2(n)) for Binary Exponentiation
// T.C. = O(log2(m) * log2(n))
// S.C. = O(1)
int nthRoot(int n, int m) {
    // Code here
    int lo = 1;
    int hi = m;
    while(lo <= hi) {
        int mid = lo + (hi-lo) / 2;
        if(evaluate(mid,n) == m) {
            return mid;
        }
        else if(evaluate(mid,n) < m) {
            lo = mid + 1;
        } 
        else { // evaluate(mid,n) > m
            hi = mid - 1;
        }
    }
    return -1;
}


int main()
{
    cout<<nthRootNaive(4,625)<<endl; // 5
    cout<<nthRoot(4,625)<<endl; // 5
    return 0;
}