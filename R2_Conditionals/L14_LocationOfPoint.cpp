#include <iostream>
using namespace std;
int main()
{
    int x;
    cout<<"Enter x coordinate : ";
    cin>>x;
    int y;
    cout<<"Enter y coordinate : ";
    cin>>y;

    if(x == 0 && y == 0) {
        cout<<"Point lie on Origin"<<endl;
    }
    else if(y == 0) {
        cout<<"Point lie on X-axix"<<endl;
    }
    else if(x == 0) {
        cout<<"Point lie on Y-axix"<<endl;
    }
    else if(x > 0 && y > 0) {
        cout<<"Point lie on 1st Quadrant"<<endl;
    }
    else if(x < 0 && y > 0) {
        cout<<"Point lie on 2nd Quadrant"<<endl;
    }
    else if(x < 0 && y < 0) {
        cout<<"Point lie on 3rd Quadrent"<<endl;
    }
    else if(x > 0 && y < 0) {
        cout<<"Point lie on 4th Quadrant"<<endl;
    }
    return 0;
}

