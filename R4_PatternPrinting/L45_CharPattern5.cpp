#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    for(int i = 1 ; i <= n ; i++) {
        int a = 65;
        for(int j = 1 ; j <= n-i ; j++) {
            cout<<"  ";
        }
        for(int j = 1 ; j <= i ; j++) {
            cout<<(char)a<<" ";
            a++;
        }
        cout<<endl;
    }
    return 0;
}

// Enter n : 5
//         A 
//       A B 
//     A B C 
//   A B C D 
// A B C D E 