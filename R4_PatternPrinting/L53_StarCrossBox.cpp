#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter n : "; // n : odd & n : even
    cin>>n;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= n ; j++) {
            if((i == j) || (i + j == n + 1) ||
            (i == 1) || (j == 1) || (i == n) || (j == n)) {
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
// * * * * * 
// * *   * * 
// *   *   * 
// * *   * * 
// * * * * * 

// Enter n : 6
// * * * * * * 
// * *     * * 
// *   * *   * 
// *   * *   * 
// * *     * * 
// * * * * * * 


// Enter n : 9
// * * * * * * * * * 
// * *           * * 
// *   *       *   * 
// *     *   *     * 
// *       *       * 
// *     *   *     * 
// *   *       *   * 
// * *           * * 
// * * * * * * * * * 

// Enter n : 10
// * * * * * * * * * * 
// * *             * * 
// *   *         *   * 
// *     *     *     * 
// *       * *       * 
// *       * *       * 
// *     *     *     * 
// *   *         *   * 
// * *             * * 
// * * * * * * * * * * 