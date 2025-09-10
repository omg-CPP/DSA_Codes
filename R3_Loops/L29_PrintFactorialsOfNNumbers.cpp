#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter num : ";
    cin>>n;
    int fact = 1;
    for(int i = 1 ; i <= n ; i++) {
        fact = fact * i;
        cout<<"Factorial of "<<i<<" is : "<<fact<<endl;
    }
    return 0;
}

// Enter num : 5
// Factorial of 1 is : 1
// Factorial of 2 is : 2
// Factorial of 3 is : 6
// Factorial of 4 is : 24
// Factorial of 5 is : 120