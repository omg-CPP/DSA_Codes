// Write a program to store 10 at every index of a 2D matrix with 5 rows and 5 columns.

#include <iostream>
using namespace std;
int main()
{
    int matrix[5][5];
    for(int i = 0 ; i < 5 ; i++) {
        for(int j = 0 ; j < 5 ; j++) {
            matrix[i][j] = 10;
        }
    }
    for(int i = 0 ; i < 5 ; i++) {
        for(int j = 0 ; j < 5 ; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// 10 10 10 10 10 
// 10 10 10 10 10 
// 10 10 10 10 10 
// 10 10 10 10 10 
// 10 10 10 10 10 