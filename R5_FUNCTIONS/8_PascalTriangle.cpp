#include <iostream>
using namespace std;
int main()
{
    int n; // suppose n = 5 (0 to 5)
    cout<<"Enter n : ";
    cin>>n;
    int nsp = n;
    for(int i = 0 ; i <= n ; i++) {
        int curr = 1;
        // for printing spaces
        for(int k = 1 ; k <= nsp ; k++) {
            cout<<" ";
        }
        for(int j = 0 ; j <= i ; j++) {
            cout<<curr<<" ";
            curr = curr*(i-j)/(j+1);
            // at some point (i-j)/(j+1) becomes between 0 and 1 so it will result in 0
        }
        nsp--;
        cout<<endl;
    }    
    return 0;
}

// Enter n : 4 (0 to 4)
//     1 
//    1 1 
//   1 2 1 
//  1 3 3 1 
// 1 4 6 4 1 


// Enter n : 5 (0 to 5)
//      1 
//     1 1 
//    1 2 1 
//   1 3 3 1 
//  1 4 6 4 1 
// 1 5 10 10 5 1 