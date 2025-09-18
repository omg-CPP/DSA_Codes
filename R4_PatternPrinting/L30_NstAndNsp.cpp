#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter no of rows : ";
    cin>>n;
    int nst = 1;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= nst ; j++) {
            cout<<"* ";
        }
        nst += 2;
        cout<<endl;
    }
    return 0;
}

// Enter no of rows : 5
// * 
// * * * 
// * * * * * 
// * * * * * * * 
// * * * * * * * * * 