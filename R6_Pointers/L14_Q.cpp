// Predict the output of the following code snippet.
#include <iostream>
using namespace std;
int main()
{
    int a = 10, b = 20;
    int* ptr = &a;
    b = *ptr + 1;
    ptr = &b;
    cout<<*ptr<<" "<<a<<" "<<b; // 11 10 11
    return 0;
}

// ptr points to a, b = a + 1 , so ptr points to b