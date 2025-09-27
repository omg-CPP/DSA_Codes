#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
using namespace std;
int mini(int x, int y) {
    if(x < y) {
        return x;
    }
    else {
        return y;
    }
}
int maxi(int x, int y) {
    if(x > y) {
        return x;
    }
    else {
        return y;
    }
}
int main()
{
    // inbuilt function
    cout<<min(40,63); // 40
    cout<<endl;
    // function created
    cout<<mini(4, 7); // 4
    cout<<endl;
    cout<<max(40,63); // 63
    cout<<endl;
    cout<<maxi(4, 7); // 7
    cout<<endl;
    cout<<sqrt(7); // 2.64575
    cout<<endl;
    cout<<sqrt(9); // 3
    return 0;
}