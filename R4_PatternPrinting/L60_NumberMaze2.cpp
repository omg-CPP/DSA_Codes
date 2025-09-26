#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter no of rows : ";
    cin>>n;

    for(int i = 1 ; i <= 2*n-1 ; i++) {
        for(int j = 1 ; j <= 2*n-1 ; j++) {
            int a = i;
            if(i > n) {
                a = 2*n-i;
            }
            int b = j;
            if(j > n) {
                b = 2*n-j;
            }
            cout<<(n+1-min(a,b))<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// Enter no of rows : 4
// 4 4 4 4 4 4 4 
// 4 3 3 3 3 3 4 
// 4 3 2 2 2 3 4 
// 4 3 2 1 2 3 4 
// 4 3 2 2 2 3 4 
// 4 3 3 3 3 3 4 
// 4 4 4 4 4 4 4 