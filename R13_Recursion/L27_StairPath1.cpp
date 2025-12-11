#include <iostream>
using namespace std;

// There are n stairs, and a person standing at the bottom wants to climb stairs to reach the top. The person can climb either 1 stair or 2 stairs at a time, the task is to count the number of ways that a person can reach at the top.

// noOfWays = stairPath(n-1) + stairPath(n-2)
// stairPath(n-1) = if one step is taken first
// stairPath(n-2) = if two steps are taken first

int stairPath(int n) {
    // base case 
    if(n == 1) { // 1 stair left to climb
        return 1;
    }
    if(n == 2) { // 2 steps left to climb
        return 2;
    }
    int noOfWays = stairPath(n-1) + stairPath(n-2);
    return noOfWays;
}

int main()
{
    int n;
    cout<<"Enter the number of stairs : ";
    cin>>n;
    cout<<stairPath(n)<<endl;
    return 0;
}

// Enter the number of stairs : 5
// 8

// Enter the number of stairs : 4
// 5