#include <iostream>
using namespace std;
// while loop -> replacement of for loop
int main()
{
    // Using for loop
    for(int i = 1 ; i <= 10 ; i++) {
        cout<<i<<" ";
    }
    // 1 2 3 4 5 6 7 8 9 10 
    cout<<endl;

    // Using while loop
    int i = 1; // initialisation
    while(i <= 10) { // condition
        cout<<i<<" ";
        i++; // increment/decrement
    }
    // 1 2 3 4 5 6 7 8 9 10 
    cout<<endl;

    // for loop as while loop
    int j = 1;
    for(; j <= 10 ;) {
        cout<<j<<" ";
        j++;
    }
    // 1 2 3 4 5 6 7 8 9 10 
    cout<<endl;
    return 0;
}