#include <iostream>
using namespace std;
int main()
{
    // Fibonacci Series :
    // 1 1 2 3 5 8 13 21 34 55 89 ----
    // 8th term = 6th term + 7th term
    int n;
    cout<<"Enter num : ";
    cin>>n;
    int a = 1;
    int b = 1;
    int sum;
    for(int i = 1 ; i <= n-2 ; i++) {
        sum = a + b;
        a = b;
        b = sum;
    }
    cout<<"The Nth Fibonacci Number is : "<<sum<<endl;
    return 0;
}

// Enter num : 6
// The Nth Fibonacci Number is : 8

// Enter num : 8
// The Nth Fibonacci Number is : 21