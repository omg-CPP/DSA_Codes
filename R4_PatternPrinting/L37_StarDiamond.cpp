#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter n : "; // n : odd
    cin>>n;
    int nst = 1;
    int nsp = n/2;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= nsp ; j++) {
            cout<<"  ";
        }
        for(int j = 1 ; j <= nst ; j++) {
            cout<<"* ";
        }
        if(i < (n/2 + 1))
        {
            nsp--;
            nst += 2;
        }
        else
        {
            nsp++;
            nst -= 2;
        }
        cout<<endl;
    }
    return 0;
}

// Enter n : 7
//       * 
//     * * * 
//   * * * * * 
// * * * * * * * 
//   * * * * * 
//     * * * 
//       * 