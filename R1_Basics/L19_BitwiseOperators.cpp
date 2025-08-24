#include <iostream>
using namespace std;
int main()
{
    int x = 7;
    // Binary Equivalent : 2^2 + 2^1 + 2^0 = 4 + 2 + 1 = 7 -> 0 1 1 1
    int y = 8;
    // Binary Equivalent : 2^3 + 0 + 0 + 0 = 8 -> 1 0 0 0
    cout<<(x<<2)<<endl; // 28
    // Left Shift : 0 0 1 1 1 -> 1 1 1 0 0 -> 2^4 + 2^3 + 2^2 + 0 + 0 = 28
    cout<<(x>>2)<<endl; // 1
    // Right Shift : 0 1 1 1 -> 1
    cout<<(x&y)<<endl; // 0 -> 0 0 0 0
    // x&y -> Bitwise AND
    cout<<(x|y)<<endl; // 15 -> 1 1 1 1 -> 2^3 + 2^2 + 2^1 + 2^0 = 15
    // x|y -> Bitwise OR
    return 0;
}