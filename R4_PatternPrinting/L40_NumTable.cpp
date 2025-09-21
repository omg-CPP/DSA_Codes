#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter n : "; 
    cin>>n;
    int nst = n-1;
    int nsp = 1;
    for(int i = 1 ; i <= 2*n-1 ; i++) {
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i = 1 ; i <= n-1 ; i++) {
        int a = 1;
        for(int j = 1 ; j <= nst ; j++) {
            cout<<a<<" ";
            a++;
        }
        for(int j = 1 ; j <= nsp ; j++) {
            cout<<"  ";
            a++;
        }
        for(int j = 1 ; j <= nst ; j++) {
            cout<<a<<" ";
            a++;
        }
        nst--;
        nsp += 2;
        cout<<endl;
    }
    return 0;
}

// Enter n : 4
// 1 2 3 4 5 6 7 
// 1 2 3   5 6 7 
// 1 2       6 7 
// 1           7 

// Enter n : 5
// 1 2 3 4 5 6 7 8 9 
// 1 2 3 4   6 7 8 9 
// 1 2 3       7 8 9 
// 1 2           8 9 
// 1               9 