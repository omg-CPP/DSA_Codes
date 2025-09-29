// Write a function to count the number of digits in a number and then print the square of this number.

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int square(int num) {
    int ans = num*num;
    return ans;
}

int countNumberOfDigits(int num) {
    int count = 0;
    while(num > 0) {
        num = num/10;
        count++;
    }
    return count;
}
int main() 
{
    int num;
    cout<<"Enter num : ";
    cin>>num;
    int numberOfDigits = countNumberOfDigits(num);
    cout<<square(numberOfDigits)<<endl;
    return 0;
}

// Enter num : 12345
// 25

// Enter num : 1234
// 16