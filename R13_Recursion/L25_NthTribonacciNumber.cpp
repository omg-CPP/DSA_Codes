#include <iostream>
using namespace std;

// Tribonacci Series : 
// 0 0 1 1 2 4 7 13 24 44 81 149 274 --- value
// 0 1 2 3 4 5 6  7  8  9 10  11  12 --- terms

// n == 0 => return 0
// n == 1 => return 0
// n == 2 => return 1

// T.C. = Total Calls * Work Done in each call
// Draw recursion tree and than analyze
// T.C. = (3^0 + 3^1 + 3^2 + 3^3 + ------ + 3^n-1) * (O(1))
// T.C. = (1*(3^n - 1)) / (3 - 1) = (3^n - 1)/2
// T.C. = O(3^n) = exponential time complexity

// Space Complexity : Depth of Recursion Tree * Space in each call
//                  : Height of the Call Stack * Memory in each call

// Depth : 0 to n-1 : n levels : n depth 
// S.C. : n*1 = O(n)

int tribonacci(int n) {
    // base cases
    if(n == 0 || n == 1) {
        return 0;
    }
    if(n == 2) {
        return 1;
    }
    int tri = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
    return tri;
}

int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    int nthTribonacciNumber = tribonacci(n);
    cout<<nthTribonacciNumber<<endl;
    return 0;
}

// Enter n : 9
// 44

// Enter n : 11
// 149

// Enter n : 5
// 4