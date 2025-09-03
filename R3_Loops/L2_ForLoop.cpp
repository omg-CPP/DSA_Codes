#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    for(int i = 1 ; i <= n ; i++) {
        cout<<"Hello World"<<endl;
    }
    // for(initialisation ; condition ; increment/decrement) { body }
    // When condition fails, the loop breaks.
    return 0;
}

// Enter n : 3
// Hello World
// Hello World
// Hello World