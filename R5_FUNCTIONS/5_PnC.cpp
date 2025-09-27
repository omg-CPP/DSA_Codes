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
    int r;
    cout<<"Enter r : ";
    cin>>r;
    // int nfact = factorial(n); // n!
    // int rfact = factorial(r); // r!
    // int nrfact = factorial(n-r); // (n-r)!
    // int nCr = nfact/(rfact*nrfact);
    int nCr = combination(n,r);
    cout<<nCr<<endl;
    int nPr = permutation(n,r);
    cout<<nPr<<endl;
    return 0;
}

// Enter n : 5
// Enter r : 2
// 10
// 20

// Enter n : 6
// Enter r : 2
// 15
// 30