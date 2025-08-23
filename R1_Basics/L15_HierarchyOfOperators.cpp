#include <iostream>
using namespace std;
int main()
{
    // BODMAS -> Brackets > %,/,* > +,-
    // In C++ -> left to right operations takes place
    int i = 2*3/4;
    cout<<(i); // 1
    return 0;
}