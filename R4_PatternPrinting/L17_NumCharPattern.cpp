#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter no of rows : ";
    cin>>n;
    for(int i = 1 ; i <= n ; i++) {
        if(i % 2 != 0) {
            for(int j = 1 ; j <= i ; j++) {
                cout<<j<<" ";
            }
        }
        else {
            int x = 65;
            for(int j = 1 ; j <= i ; j++) {
                cout<<(char)x<<" ";
                x++;
            }
        }
        cout<<endl;
    }
    return 0;
}

// Enter no of rows : 5
// 1 
// A B 
// 1 2 3 
// A B C D 
// 1 2 3 4 5 