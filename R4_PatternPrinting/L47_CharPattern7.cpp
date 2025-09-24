#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    int a = 1;
    for(int i = 1 ; i <= n ; i++) {
        int b = 65;
        for(int j = 1 ; j <= a ; j++) {
            cout<<(char)b<<" ";
            b++;
        }
        a += 2;
        cout<<endl;
    }
    return 0;
}

// Enter n : 5
// A 
// A B C 
// A B C D E 
// A B C D E F G 
// A B C D E F G H I 