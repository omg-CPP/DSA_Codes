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
            cout<<"* ";
        }
        for(int j = 1 ; j <= nsp ; j++) {
            cout<<"  ";
        }
        for(int j = 1 ; j <= nst ; j++) {
            cout<<"* ";
        }
        nsp += 2;
        nst--;
        cout<<endl;
    }

    int nstd = 1;
    int nspd = 2*n-2;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= nstd ; j++) {
            cout<<"* ";
        }
        for(int j = 1 ; j <= nspd ; j++) {
            cout<<"  ";
        }
        for(int j = 1 ; j <= nstd ; j++) {
            cout<<"* ";
        }
        nspd -= 2;
        nstd++;
        cout<<endl;
    }
    return 0;
}

// Enter n : 4
// * * * * * * * * 
// * * *     * * * 
// * *         * * 
// *             * 
// *             * 
// * *         * * 
// * * *     * * * 
// * * * * * * * * 

// Enter n : 5
// * * * * * * * * * * 
// * * * *     * * * * 
// * * *         * * * 
// * *             * * 
// *                 * 
// *                 * 
// * *             * * 
// * * *         * * * 
// * * * *     * * * * 
// * * * * * * * * * * 