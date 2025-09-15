#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter no of rows : ";
    cin>>n;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= 2*i-1 ; j++) {
            if(j % 2 != 0) {
                cout<<j<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}

// Enter no of rows : 4
// 1 
// 1 3 
// 1 3 5 
// 1 3 5 7 

// Enter no of rows : 5
// 1 
// 1 3 
// 1 3 5 
// 1 3 5 7 
// 1 3 5 7 9 