#include <iostream>
using namespace std;
int main()
{
//        int x = 5;
//        cout<<(x++); // 5
//        cout<<(x); // 6
//        cout<<(x--); // 6
//        cout<<(x); // 5
//        cout<<(++x); // 6
//        cout<<(x); // 6
//        cout<<(--x); // 5
//        cout<<(x); // 5

    int a = 2 , b = 3 , c = 1;
    int t = a + --c + b++ + b;
    // t = 2 + 0 + 3 + 4 = 9
    cout<<(t)<<endl; // 9

    a += a++ + ++a/2;
    // a = a + a++ + ++a/2
    // a = 2 + 2 + 4/2 = 6
    cout<<(a)<<endl;


    int w = 8;
    w += ++w + w-- + --w;
    // w = w + ++w + w-- + --w;
    // w = 8 + 9 + 9 + 7 = 33
    cout<<(w)<<endl;

    int g = 4 , h = 5;
    h = g++ + g--;
    // h = 4 + 5 = 9
    g = ++h + h--;
    // g = 10 + 10 = 20
    cout<<(g)<<endl; // 20
    cout<<(h)<<endl; // 9

    int i = 3;
    int j = ++i + i++ + --i;
    // j = 4 + 4 + 4 = 12
    cout<<(j)<<endl; // 12

    int d = 4;
    // left to right precedence and then BODMAS
    int r = d++ + --d + d-- + ++d + d/4 + d++*3 + d + d--;
    // r = 4 + 4 + 4 + 4 + 4/4 + 4*3 + 5 + 5
    // r = 4 + 4 + 4 + 4 + 1 + 12 + 5 + 5 = 39
    // d = 4
    cout<<(r)<<endl; // 39
    return 0;
}