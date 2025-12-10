#include <iostream>
using namespace std;

int fibonacciOfFirstNNatural(int n) {
    if(n == 1 || n == 2) {
        return 1;
    }
    int fibonacci = fibonacciOfFirstNNatural(n-1) + fibonacciOfFirstNNatural(n-2);
    return fibonacci;
}
int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    for(int i = 1 ; i <= n ; i++) {
        cout<<i<<" : "<<fibonacciOfFirstNNatural(i)<<endl;
    }
    return 0;
}

// Enter n : 11
// 1 : 1
// 2 : 1
// 3 : 2
// 4 : 3
// 5 : 5
// 6 : 8
// 7 : 13
// 8 : 21
// 9 : 34
// 10 : 55
// 11 : 89