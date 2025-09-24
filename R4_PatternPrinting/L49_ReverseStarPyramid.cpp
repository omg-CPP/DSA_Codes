#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    int nsp = 0;
    int nst = 2*n-1;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= nsp ; j++) {
            cout<<"  ";
        }
        for(int j = 1 ; j <= nst ; j++) {
            cout<<"* ";
        }
        nst -= 2;
        nsp++;
        cout<<endl;
    }
    return 0;
}

// Enter n : 6
// * * * * * * * * * * * 
//   * * * * * * * * * 
//     * * * * * * * 
//       * * * * * 
//         * * * 
//           * 

// Enter n : 5
// * * * * * * * * * 
//   * * * * * * * 
//     * * * * * 
//       * * * 
//         * 