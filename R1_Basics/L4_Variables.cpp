#include <iostream>
using namespace std;
int main()
{
    // Variables as containers

    int x; // Initialisation
    x = 7; // Assignment
    cout<<x<<endl; // 7

    x = 10; // Updation
    cout<<x<<endl; // 10

    x = 19; // Updation
    cout<<x<<endl; // 19

    x = x + 10; // Updation => x += 10;
    cout<<x<<endl; // 29

    x = x - 20; // Updation => x -= 20
    cout<<x<<endl; // 9

    x = x * 6; // Updation => x *= 6;
    cout<<x<<endl; // 54
    return 0;
}