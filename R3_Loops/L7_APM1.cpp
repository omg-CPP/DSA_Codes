#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter no of terms : ";
    cin>>n;
    // AP -> 1,3,5,7,9,---,n terms
    // An = a + (n-1)*d = 1 + (n-1)*2 = 2*n - 1
    // a -> first term
    // d -> common difference
    for(int i = 1 ; i <= 2*n - 1 ; i += 2) {
        cout<<i<<" ";
    }
    // Enter no of terms : 10
    // 1 3 5 7 9 11 13 15 17 19 

    // Enter no of terms : 20
    // 1 3 5 7 9 11 13 15 17 19 21 23 25 27 29 31 33 35 37 39 
    cout<<endl;
    return 0;
}