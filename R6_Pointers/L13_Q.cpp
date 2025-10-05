// Write a program to find out the product of two numbers using pointers.

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    int x, y;
    cout<<"Enter x : ";
    cin>>x;
    cout<<"Enter y : ";
    cin>>y;
    int* ptrX = &x; 
    int* ptrY = &y;
    int ans;
    int* ptrAns = &ans;
    *ptrAns = (*ptrX)*(*ptrY);
    cout<<*ptrAns<<endl; // 20
    cout<<ans<<endl; // 20
    return 0;
}
