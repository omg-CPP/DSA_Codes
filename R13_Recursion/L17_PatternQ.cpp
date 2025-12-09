// Print an increasing-decreasing sequence using recursion
// Example:
// If n = 5, the output should be:
// 1 2 3 4 5 4 3 2 1

#include <iostream>
using namespace std;

void pattern(int current, int n) {
    if(current > n) {
        return;
    }
    // work
    cout<<current<<" ";
    // recursive call
    pattern(current+1,n);
    // unwind recursion
    if(current != n) {
        cout<<current<<" ";
    }
    return;
}

int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    pattern(1,n);
    return 0;
}

// Enter n : 5
// 1 2 3 4 5 4 3 2 1 

// Step	Call Stack	Action
// 1	printSequence(1, 3)	Print 1
// 2	printSequence(1, 3)
//      → printSequence(2, 3)	Print 2
// 3	printSequence(1, 3)
//      → printSequence(2, 3)
//      → printSequence(3, 3)	Print 3
// 4	printSequence(1, 3)
//      → printSequence(2, 3)
//      → printSequence(3, 3)
//      → printSequence(4, 3)	Return (since 4 > 3)
// 5	Unwind printSequence(3, 3)	(Skip print since current==n)
// 6	Unwind printSequence(2, 3)	Print 2
// 7	Unwind printSequence(1, 3)	Print 1
// 8	Program ends	