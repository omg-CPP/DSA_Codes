#include <iostream>
using namespace std;
int sum(int x, int y) {
    return x+y; 
}
int main()
{
    int x = 2;
    int y = 9;
    // Function Calling
    cout<<sum(x, y); // 11
    return 0;
}