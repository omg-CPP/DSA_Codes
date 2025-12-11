#include <iostream>
using namespace std;

// There are n stairs, and a person standing at the bottom wants to climb the stairs to
// reach the nth stair. The person can climb either 1, 2, or 3 stairs at a time. Write a
// program to count the number of ways the person can reach the top using recursion.

int climbingStairs(int n) {
    // base case 
    if(n == 0) {
        return 0;
    }
    if(n == 1) { // 1 stair left to climb
        return 1;
    }
    if(n == 2) { // 2 steps left to climb
        return 2;
    }
    if(n == 3) { // 3 steps left to climb
        return 4;
    }
    int noOfWays = climbingStairs(n-1) + climbingStairs(n-2) + climbingStairs(n-3);
    return noOfWays;
}

int main()
{
    int n;
    cout<<"Enter the number of stairs : ";
    cin>>n;
    cout<<climbingStairs(n)<<endl;
    return 0;
}

// Enter the number of stairs : 4
// 7

// Enter the number of stairs : 6
// 24