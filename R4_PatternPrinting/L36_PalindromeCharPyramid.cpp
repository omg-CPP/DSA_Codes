#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    int nst = 1;
    int nsp = n-1;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= nsp ; j++) {
            cout<<"  ";
        }

        int x = 65;
        for(int j = 1 ; j <= i ; j++) {
            cout<<(char)x<<" ";
            x++;
        }

        int m = x-2;
        for(int j = 1 ; j <= i-1 ; j++) {
            cout<<(char)m<<" ";
            m--;
        }
        nsp -= 1;
        cout<<endl;
    }
    return 0;
}

// Enter n : 5
//         A 
//       A B A 
//     A B C B A 
//   A B C D C B A 
// A B C D E D C B A 