// Given two numbers a and b, write a function to print all odd numbers between them.

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void printOddNumbers(int a, int b) {
    if(a > b) {
        printOddNumbers(b,a);
        return;
    }
    for(int i = a ; i <= b ; i++) {
        if(i % 2 != 0) {
            cout<<i<<" ";
        }
    }
    cout<<endl;
}
int main() 
{
    int a, b;
    cout<<"Enter a : ";
    cin>>a;
    cout<<"Enter b : ";
    cin>>b;
    printOddNumbers(a,b);
    return 0;
}

// Enter a : 1
// Enter b : 20
// 1 3 5 7 9 11 13 15 17 19 

// Enter a : 20
// Enter b : 11
// 11 13 15 17 19 