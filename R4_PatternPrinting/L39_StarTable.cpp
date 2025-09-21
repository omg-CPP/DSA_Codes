#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter n : "; 
    cin>>n;
    int nst = n-1;
    int nsp = 1;
    for(int i = 1 ; i <= 2*n-1 ; i++) {
        cout<<"* ";
    }
    cout<<endl;
    for(int i = 1 ; i <= n-1 ; i++) {
        for(int j = 1 ; j <= nst ; j++) {
            cout<<"* ";
        }
        for(int j = 1 ; j <= nsp ; j++) {
            cout<<"  ";
        }
        for(int j = 1 ; j <= nst ; j++) {
            cout<<"* ";
        }
        nst--;
        nsp += 2;
        cout<<endl;
    }
    return 0;
}

// Enter n : 4
// * * * * * * * 
// * * *   * * * 
// * *       * * 
// *           * 

// Enter n : 5
// * * * * * * * * * 
// * * * *   * * * * 
// * * *       * * * 
// * *           * * 
// *               * 

// Enter n : 8
// * * * * * * * * * * * * * * * 
// * * * * * * *   * * * * * * * 
// * * * * * *       * * * * * * 
// * * * * *           * * * * * 
// * * * *               * * * * 
// * * *                   * * * 
// * *                       * * 
// *                           * 


