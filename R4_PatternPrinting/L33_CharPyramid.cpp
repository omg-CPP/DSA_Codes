#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter no of rows : ";
    cin>>n;
    int nst = 1;
    int nsp = n-1;
    for(int i = 1 ; i <= n ; i++) {
        int x = 65;
        for(int j = 1 ; j <= nsp ; j++) {
            cout<<"  ";
        }
        for(int j = 1 ; j <= nst ; j++) {
            cout<<(char)x<<" ";
            x++;
        }
        nst += 2;
        nsp -= 1;
        cout<<endl;
    }
    return 0;
}

// Enter no of rows : 4
//       A 
//     A B C 
//   A B C D E 
// A B C D E F G 

// Enter no of rows : 5
//         A 
//       A B C
//     A B C D E
//   A B C D E F G       
// A B C D E F G H I   