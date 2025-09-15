#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter no of rows : ";
    cin>>n;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= 2*i ; j++) {
            if(j % 2 == 0) {
                cout<<j<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}

// Enter no of rows : 4
// 2 
// 2 4 
// 2 4 6 
// 2 4 6 8 

// Enter no of rows : 5
// 2 
// 2 4 
// 2 4 6 
// 2 4 6 8 
// 2 4 6 8 10 