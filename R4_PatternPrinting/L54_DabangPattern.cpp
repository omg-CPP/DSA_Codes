#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter n : "; 
    cin>>n;
    int nst = n;
    int nsp = 0;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= nst ; j++) {
            cout<<j<<" ";
        }
        for(int j = 1 ; j <= nsp ; j++) {
            cout<<"* ";
        }
        for(int j = nst ; j >= 1 ; j--) {
            cout<<j<<" ";
        }
        nsp += 2;
        nst--;
        cout<<endl;
    }
    return 0;
}

// Enter n : 5
// 1 2 3 4 5 5 4 3 2 1 
// 1 2 3 4 * * 4 3 2 1 
// 1 2 3 * * * * 3 2 1 
// 1 2 * * * * * * 2 1 
// 1 * * * * * * * * 1 

// Enter n : 6
// 1 2 3 4 5 6 6 5 4 3 2 1 
// 1 2 3 4 5 * * 5 4 3 2 1 
// 1 2 3 4 * * * * 4 3 2 1 
// 1 2 3 * * * * * * 3 2 1 
// 1 2 * * * * * * * * 2 1 
// 1 * * * * * * * * * * 1 