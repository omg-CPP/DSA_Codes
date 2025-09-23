#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter n : "; 
    cin>>n;
    int nst = n-1;
    int nsp = 1;
    int x = 65;
    for(int i = 1 ; i <= 2*n-1 ; i++) {
        cout<<(char)x<<" ";
        x++;
    }
    cout<<endl;
    for(int i = 1 ; i <= n-1 ; i++) {
        int a = 65;
        for(int j = 1 ; j <= nst ; j++) {
            cout<<(char)a<<" ";
            a++;
        }
        for(int j = 1 ; j <= nsp ; j++) {
            cout<<"  ";
            a++;
        }
        for(int j = 1 ; j <= nst ; j++) {
            cout<<(char)a<<" ";
            a++;
        }
        nst--;
        nsp += 2;
        cout<<endl;
    }
    return 0;
}

// Enter n : 4
// A B C D E F G 
// A B C   E F G 
// A B       F G 
// A           G 

// Enter n : 5
// A B C D E F G H I 
// A B C D   F G H I 
// A B C       G H I 
// A B           H I 
// A               I 