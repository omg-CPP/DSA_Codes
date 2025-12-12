#include <iostream>
using namespace std;

int sumOfDigits(int n) {
    if(n == 0) {
        return 0;
    }
    int sum = (n % 10) + sumOfDigits(n / 10);
    return sum;
}

int main()
{
    int n;
    cout<<"Enter any number : ";
    cin>>n;
    cout<<sumOfDigits(n);
    return 0;
}

// Enter any number : 1234
// 10

// Enter any number : 12345
// 15