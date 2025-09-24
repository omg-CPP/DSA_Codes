#include <iostream>
using namespace std;

int factorial(int n) {
    int fact = 1;
    for(int i = 1 ; i <= n ; i++)
    {
        fact = fact*i;
    }
    return fact;
}

int combination(int n , int r) {
    int ncr = factorial(n)/(factorial(r)*factorial(n-r));
    return ncr;
}

int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    int nsp = n;
    for(int i = 0 ; i <= n ; i++) {
        for(int j = 0 ; j <= nsp ; j++) {
            cout<<" ";
        }
        for(int j = 0 ; j <= i ; j++) {
            int icj = combination(i,j);
            cout<<icj<<" ";
        }
        nsp--;
        cout<<endl;
    }
    return 0;
}

// Enter n : 4
//      1 
//     1 1 
//    1 2 1 
//   1 3 3 1 
//  1 4 6 4 1 

// Enter n : 5
//       1 
//      1 1 
//     1 2 1 
//    1 3 3 1 
//   1 4 6 4 1 
//  1 5 10 10 5 1 
