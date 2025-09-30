#include <iostream>
using namespace std;

int maxOfThree(int a, int b, int c) {
    if(a > b && a > c) {
        return a;
    }
    else if(b > c && b > a) {
        return b;
    }
    else {
        return c;
    }
}
int main()
{
    int a = 200;
    int b = 9;
    int c = 79;
    cout<<maxOfThree(a,b,c); // 200
    return 0;
}