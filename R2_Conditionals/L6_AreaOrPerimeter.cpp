#include <iostream>
using namespace std;
int main()
{
    int l;
    cout<<"Enter length : ";
    cin>>l;
    int b;
    cout<<"Enter breadth : ";
    cin>>b;

    int area = l * b;
    int perimeter = 2 * (l + b);

    if(area > perimeter) {
        cout<<"Area is greater than Perimeter"<<endl;
    }
    else {
        cout<<"Perimeter is greater than Area"<<endl;
    }
    return 0;
}

// Enter length : 5
// Enter breadth : 4
// Area is greater than Perimeter