// Predict the output of the following code snippet.

#include <iostream>
using namespace std;
int main()
{
    int a = 10, b = 20;
    // int *ptr;
    // *ptr = 5;
    cout<<a<<" "<<b<<endl; // 10 20
    // cout<<ptr<<endl;
    // cout<<*ptr<<endl;
    return 0;
}


// The program is correct and will compile but might result in runtime error.This is
// because ptr will have a garbage address which might even point to a location which
// does not belong to our program and hence might result in Segmentation Fault when we
// are trying to access it.

// After commenting ptr

// PS C:\Users\hp\OneDrive\Desktop\DSA\R6_POINTERS> g++ L16_Q.cpp -o L16_Q
// PS C:\Users\hp\OneDrive\Desktop\DSA\R6_POINTERS> ./L16_Q.exe
// 10 20