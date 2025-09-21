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
        for(int j = 1 ; j <= nsp ; j++) {
            cout<<"  ";
        }
        for(int j = 1 ; j <= nst ; j++) {
            cout<<"* ";
        }
        nsp++;
        cout<<endl;
    }
    return 0;
}

// Enter n : 4
// * * * * 
//   * * * * 
//     * * * * 
//       * * * * 