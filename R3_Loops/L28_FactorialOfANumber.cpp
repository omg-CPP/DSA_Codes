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
    }
    cout<<"Factorial of the number is : "<<fact<<endl;
    return 0;
}

// Enter num : 5
// Factorial of the number is : 120