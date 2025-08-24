#include <iostream>
using namespace std;
int main()
{

    // Relational Operators :
    // == -> Is equal to -> 4 == 5 returns false
    // != -> Not equal to -> 1 != 5 returns true
    // > -> Greater than -> 1 > 5 returns false
    // < -> Less than -> 2 < 5 returns true
    // >= -> Greater than or equal to -> 4 >= 5 returns false
    // <= -> Less than or equal to -> 1 <= 5 returns true

    int x = 4;
    int y = 3;
    int z = 4;
    cout<<(x==y)<<endl; // 0
    cout<<(x!=y)<<endl; // 1
    cout<<(x>=y)<<endl; // 1
    cout<<(x<=y)<<endl; // 0
    cout<<(x>y)<<endl; // 1
    cout<<(x<y)<<endl; // 0
    // cout<<(x=y)<<endl; // 3
    cout<<(!(x==y))<<endl; // 1
    cout<<(!(x!=y))<<endl; // 0
    return 0;
}