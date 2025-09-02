#include <iostream>
using namespace std;
int main()
{
    double x1 = 1, x2 = 2, x3 = 3, y1 = 1, y2 = 2, y3 = 4;
    double m1 = (y2-y1)/(x2-x1);
    double m2 = (y3-y2)/(x3-x2);
    if(m1 == m2) {
        cout<<"Collinear Points"<<endl;
    }
    else {
        cout<<"Non-Collinear Points"<<endl;
    }
    return 0;
}

// Non-Collinear Points