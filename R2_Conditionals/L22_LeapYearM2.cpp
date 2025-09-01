#include <iostream>
using namespace std;
int main()
{
    int year;
    cout<<"Enter the year : ";
    cin>>year;

    if(((year % 100 != 0) && (year % 4 == 0)) || (year % 400 == 0)) {
        cout<<year<<" is a Leap Year"<<endl;
    }
    else {
        cout<<year<<" is not a Leap Year"<<endl;
    }
    return 0;
}

// Enter the year : 2100
// 2100 is not a Leap Year