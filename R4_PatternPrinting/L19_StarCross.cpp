#include <iostream>
using namespace std;
int main()
{
    // dry run recommended
    int n; // n -> odd
    cout<<"Enter no of rows : ";
    cin>>n;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= n ; j++) {
            if(i == (n/2 + 1) || j == (n/2 + 1)) {
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

// Enter no of rows : 5
//     *     
//     *     
// * * * * * 
//     *     
//     *    