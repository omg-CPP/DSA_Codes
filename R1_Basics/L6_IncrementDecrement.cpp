#include <iostream>
using namespace std;
int main()
{ 
    // Increment / Decrement
    int x = 5;
    cout<<x<<endl; // 5
    x = x + 1;
    cout<<x<<endl;; // 6
    x++; // -> post-increment
    cout<<x<<endl; // 7
    ++x; // -> pre-increment
    cout<<x<<endl; // 8

    int y = 2;
    cout<<y<<endl; // 2

    cout<<y++<<endl; // 2
    cout<<y<<endl; // 3
    
    cout<<++y<<endl; // 4
    cout<<y<<endl; // 4

    int z = 4;
    cout<<y<<endl; // 4

    cout<<--y<<endl; // 3
    cout<<y<<endl; // 3

    cout<<y--<<endl; // 3
    cout<<y<<endl; // 2
    return 0;
}