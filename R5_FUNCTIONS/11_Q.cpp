// Write a function to take the radius of a circle as an argument and return its area.

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

double area(int radius) {
    double ans = 3.14*radius*radius;
    return ans;
}

int main() 
{
    int radius;
    cout<<"Enter radius : ";
    cin>>radius;
    cout<<"Area of the circle is : "<<area(radius)<<" units square";
    return 0;
}

// Enter radius : 5
// Area of the circle is : 78.5 units square