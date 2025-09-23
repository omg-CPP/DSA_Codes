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
    for(int i = 1 ; i <= n ; i++) {
        cout<<(char)x<<" ";
        x++;
    }
    int y = x-2;
    for(int i = n-1 ; i >= 1 ; i--) {
        cout<<(char)y<<" ";
        y--;
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
        int b = a-2*i;
        for(int j = 1 ; j <= nst ; j++) {
            cout<<(char)b<<" ";
            b--;
        }
        nst--;
        nsp += 2;
        cout<<endl;
    }
    return 0;
}

// Enter n : 4
// A B C D C B A 
// A B C   C B A 
// A B       B A 
// A           A 

// Enter n : 5
// A B C D E D C B A 
// A B C D   D C B A 
// A B C       C B A 
// A B           B A 
// A               A 