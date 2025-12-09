// Write a program to print the sum of all odd numbers from a to b (inclusive) using
// recursion.

#include <iostream>
using namespace std;

int sumOfOdd(int a, int b) {
    int sum = 0;
    if(a > b) {
        return 0;
    }
    if(a % 2 != 0) {
        sum =  a + sumOfOdd(a+1,b);
    }
    else {
        sum =  sumOfOdd(a+1,b);
    }
    return sum;
}

int main()
{
    int a, b;
    cout<<"Enter a : ";
    cin>>a;
    cout<<"Enter b : ";
    cin>>b;
    int sum = sumOfOdd(a,b);
    cout<<"The sum of all odd numbers from "<<a<<" to "<<b<<" is : "<<sum<<endl;
    return 0;
}

// Enter a : 1
// Enter b : 10
// The sum of all odd numbers from 1 to 10 is : 25
