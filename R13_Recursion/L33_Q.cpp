#include <iostream>
using namespace std;
// Given an integer num, return the number of steps to reduce it to zero. In one step, if the
// current number is even, you have to divide it by 2, otherwise, you have to subtract 1
// from it. [Leetcode 1342]

int noOfSteps(int n) {
    // base case
    if(n == 0) {
        return 0;
    }
    if(n == 1) {
        return 1;
    }
    if(n % 2 == 0) { // even
        return 1 + noOfSteps(n/2);
    }
    else { // n % 2 != 0 : odd
        return 1 + noOfSteps(n-1);
    }
}

int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    cout<<noOfSteps(n)<<endl;
    return 0;
}

// Enter n : 14
// 6
// 14 -> 7 -> 6 -> 3 -> 2 -> 1 -> 0