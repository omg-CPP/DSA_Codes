#include <iostream>
using namespace std;

int factorial(int num) {
    int fact = 1;
    for(int i = 1 ; i <= num ; i++) {
        // 5! = 5 * 4!
        fact = fact*i;
    }
    return fact;
}

int combination(int n, int r) {
    int nCr = factorial(n)/(factorial(r)*factorial(n-r));
    return nCr;
}

int permutation(int n, int r) {
    int nPr = factorial(n)/factorial(n-r);
    return nPr;
}

int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    for(int i = 0 ; i <= n ; i++) {
        for(int j = 0 ; j <= i ; j++) {
            cout<<combination(i,j)<<" "; // iCj
        }
        cout<<endl;
    }
    return 0;
}

// Enter n : 5  (0 - 5)
// 1 
// 1 1 
// 1 2 1 
// 1 3 3 1 
// 1 4 6 4 1 
// 1 5 10 10 5 1 

// Enter n : 4  (0 - 4)
// 1 
// 1 1 
// 1 2 1 
// 1 3 3 1 
// 1 4 6 4 1 
