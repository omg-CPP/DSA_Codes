#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter n : "; 
    cin>>n;
    int nst = n-1;
    int nsp = 1;
    for(int i = 1 ; i <= n ; i++) {
        cout<<i<<" ";
    }
    for(int i = n-1 ; i >= 1 ; i--) {
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i = 1 ; i <= n-1 ; i++) {
        int a = 1;
        for(int j = 1 ; j <= nst ; j++) {
            cout<<a<<" ";
            a++;
        }
        for(int j = 1 ; j <= nsp ; j++) {
            cout<<"  ";
            a++;
        }
        int b = nst;
        for(int j = 1 ; j <= nst ; j++) {
            cout<<b<<" ";
            b--;
        }
        nst--;
        nsp += 2;
        cout<<endl;
    }
    return 0;
}

// Enter n : 4
// 1 2 3 4 3 2 1 
// 1 2 3   3 2 1 
// 1 2       2 1 
// 1           1 

// Enter n : 5
// 1 2 3 4 5 4 3 2 1 
// 1 2 3 4   4 3 2 1 
// 1 2 3       3 2 1 
// 1 2           2 1 
// 1               1 