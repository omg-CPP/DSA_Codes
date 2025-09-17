#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter no of rows : ";
    cin>>n;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= n ; j++) {
            if(i == j || (i+j) == n+1) {
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

// Enter no of rows : 3
// *   * 
//   *   
// *   * 

// Enter no of rows : 5
// *       * 
//   *   *   
//     *     
//   *   *   
// *       * 

// Enter no of rows : 7
// *           * 
//   *       *   
//     *   *     
//       *       
//     *   *     
//   *       *   
// *           * 

// Enter no of rows : 8
// *             * 
//   *         *   
//     *     *     
//       * *       
//       * *       
//     *     *     
//   *         *   
// *             * 