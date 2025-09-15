#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter no of rows : ";
    cin>>n;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j < i ; j++) {
            cout<<"  ";
        }
        for(int j = 1 ; j <= n-i+1 ; j++) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// Enter no of rows : 4
// 1 2 3 4 
//   1 2 3 
//     1 2 
//       1 