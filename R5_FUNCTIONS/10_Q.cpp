// Write a function to print squares of n natural numbers.

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int square(int num) {
    int ans = num*num;
    return ans;
}

void firstNSquares(int n) {
    for(int i = 1 ; i <= n ; i++) {
        cout<<i<<" "<<square(i)<<endl;
    }
}

int main() 
{
    int n;
    cout<<"Enter n : ";
    cin >> n;
    firstNSquares(n);
    return 0;
}

// Enter n : 5
// 1 1
// 2 4
// 3 9
// 4 16
// 5 25