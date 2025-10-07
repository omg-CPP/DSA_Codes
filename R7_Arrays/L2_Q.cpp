#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of students : ";
    cin>>n;
    // Array of marks of students
    int marks[n]; // (0 - n-1) : indexing
    cout<<"Enter the marks of students : ";
    for(int i = 0 ; i <= n-1 ; i++) {
        cin>>marks[i];
    }

    for(int i = 0 ; i <= n-1 ; i++) {
        if(marks[i] < 35) {
            cout<<i<<" "; // returning indices
        }
    }
    return 0;
}

// Enter number of students : 6
// Enter the marks of students : 34 87 92 21 45 13
// 0 3 5 

// Enter number of students : 7
// Enter the marks of students : 45 54 12 28 78 95 30
// 2 3 6 