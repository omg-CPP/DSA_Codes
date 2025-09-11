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
    cout<<"The 1st Fibonacci Number is : "<<a<<endl;
    cout<<"The 2nd Fibonacci Number is : "<<b<<endl;
    for(int i = 1 ; i <= n-2 ; i++) {
        sum = a+b;
        a = b;
        b = sum;
        cout<<"The "<<(i+2)<<"th Fibonacci Number is : "<<sum<<endl;
    }
    return 0;
}

// Enter num : 10
// The 1st Fibonacci Number is : 1
// The 2nd Fibonacci Number is : 1
// The 3th Fibonacci Number is : 2
// The 4th Fibonacci Number is : 3
// The 5th Fibonacci Number is : 5
// The 6th Fibonacci Number is : 8
// The 7th Fibonacci Number is : 13
// The 8th Fibonacci Number is : 21
// The 9th Fibonacci Number is : 34
// The 10th Fibonacci Number is : 55

// Enter num : 11
// The 1st Fibonacci Number is : 1
// The 2nd Fibonacci Number is : 1
// The 3th Fibonacci Number is : 2
// The 4th Fibonacci Number is : 3
// The 5th Fibonacci Number is : 5
// The 6th Fibonacci Number is : 8
// The 7th Fibonacci Number is : 13
// The 8th Fibonacci Number is : 21
// The 9th Fibonacci Number is : 34
// The 10th Fibonacci Number is : 55
// The 11th Fibonacci Number is : 89