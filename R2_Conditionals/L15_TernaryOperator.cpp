#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    cout<<((n % 2 == 0) ? "Even" : "Odd");
    return 0;
}

// Enter n : 5
// Odd

// Enter n : 8
// Even