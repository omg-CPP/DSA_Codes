#include <iostream>
using namespace std;
int main()
{
    int x = 10;
    int y = 3;
    int r = x%y;
    cout<<r<<endl; // 1

    // a % b gives the remainder when a is divided by b
    int a = 8;
    int b = 2;
    cout<<(a%b); // 0
    cout<<(4%3); // 1
    cout<<(3%4); // 3
    cout<<(4%-3); // 1
    cout<<(-4%3); // -1
    cout<<(3%-4); // 3
    cout<<(-3%4); // -3
    cout<<(-4%-3); // -1
    cout<<(-3%-4); // -3

    // a % b = a if a < b
    // a % (-b) = [a % b]
    // (-a) % b = - [a % b]
    // (-a) % (-b) = - [a % (-b)] = - [a % b]
    return 0;
}