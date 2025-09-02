#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int x;
    cout<<"Enter x coordinate : ";
    cin>>x;
    int y;
    cout<<"Enter y coordinate : ";
    cin>>y;

    int r;
    cout<<"Enter radius : ";
    cin>>r;

    int x1;
    cout<<"Enter x1 coordinate : ";
    cin>>x1;
    int y1;
    cout<<"Enter y1 coordinate : ";
    cin>>y1;

    double d = sqrt(((x-x1)*(x-x1))+((y-y1)*(y-y1)));
    if(d == r) {
        cout<<"Point lie on the Circle"<<endl;
    }
    else if(d > r) {
        cout<<"Point lie Outside the Circle"<<endl;
    }
    else { // d < r
        cout<<"Point lie Inside the Circle"<<endl;
    }
    return 0;
}

// Enter x coordinate : 0
// Enter y coordinate : 0
// Enter radius : 1
// Enter x1 coordinate : 4
// Enter y1 coordinate : 4
// Point lie Outside the Circle