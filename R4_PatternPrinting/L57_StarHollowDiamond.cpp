#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter n : ";  // n : odd
    cin>>n;
    int mid = n/2 + 1;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= n ; j++) {
            if((i+j) == mid+1 || (i+j) == mid+n || 
               (i-j) == mid-1 || (j-i) == mid-1) {
                cout<<"* ";
               }
               else {
                cout<<"  ";
               }
        }
        cout<<endl;
    }
    return 0;
}

// Enter n : 5
//     *     
//   *   *   
// *       * 
//   *   *   
//     *     

// Enter n : 7
//       *       
//     *   *     
//   *       *
// *           *
//   *       *
//     *   *
//       *


// 59 - 2 - 2 - 1 + 3 = 57