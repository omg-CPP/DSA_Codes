#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    int a = 65;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= i; j++) {
            cout<<(char)a<<" ";
            a++;
        }
        cout<<endl;
    }
    return 0;
}

// Enter n : 5
// A 
// B C 
// D E F 
// G H I J 
// K L M N O 