#include <iostream>
#include <cmath>
using namespace std;

int numberOfDigits(int n) {
    if(n == 0) {
        return 0;
    }
    return 1 + numberOfDigits(n / 10);
}

int reverseNumber(int n, int digits) {
    if(n == 0) {
        return 0;
    }
    if(n < 10) {
        return n;
    }
    int rev = ((n%10)*pow(10,digits-1)) + reverseNumber(n/10,digits-1);
    return rev;
}

int main()
{
    int n;
    cout<<"Enter a positive integer : ";
    cin>>n;
    int digits = numberOfDigits(n);
    int reversedNumber = reverseNumber(n,digits);
    cout<<reversedNumber<<endl; 
    // Enter a positive integer : 12345
    // 54321
    return 0;
}