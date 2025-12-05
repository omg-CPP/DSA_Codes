#include <iostream>
using namespace std;

// Write a function to calculate the nth fibonacci number using recursion

// 1 1 2 3 5 8 13 21 34 55 89 --- 
// 1 2 3 4 5 6  7  8  9 10 11 --- 
// fibo(n) = fibo(n-1) + fibo(n-2)

int fibonacci(int n) {
    if(n == 1 || n == 2) {
        return 1;
    }
    // int fibo = fibonacci(n-1) + fibonacci(n-2);
    // return fibo;

    int leftAns = fibonacci(n-1);
    int rightAns = fibonacci(n-2);
    return leftAns + rightAns;
}

int main()
{
    int num;
    cout<<"Enter num : ";
    cin>>num;
    cout<<fibonacci(num)<<endl;
    return 0;
}

// Enter num : 8
// 21

// Enter num : 11
// 89