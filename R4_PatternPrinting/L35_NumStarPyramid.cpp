#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    int nst = 1;
    int nsp = n-1;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= nsp ; j++) {
            cout<<"  ";
        }
        for(int j = 1 ; j <= i ; j++) {
            cout<<j<<" ";
        }
        for(int j = 1 ; j < nst ; j++) {
            cout<<"* ";
        }
        nst += 1;
        nsp -= 1;
        cout<<endl;
    }
    return 0;
}

// Enter n : 5
//         1 
//       1 2 * 
//     1 2 3 * * 
//   1 2 3 4 * * * 
// 1 2 3 4 5 * * * * 

// Enter n : 5
//         1 
//       1 2 * 
//     1 2 3 * * 
//   1 2 3 4 * * * 
// 1 2 3 4 5 * * * * 