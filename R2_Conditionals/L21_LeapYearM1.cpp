#include <iostream>
using namespace std;
int main()
{
    int year;
    cout<<"Enter the year : ";
    cin>>year;

    if(year % 400 == 0) {
        cout<<year<<" is a Leap Year"<<endl;
    }
    else if(year % 100 == 0) {
        cout<<year<<" is not a Leap Year"<<endl;
    }
    else if(year % 4 == 0) {
        cout<<year<<" is a Leap Year"<<endl;
    }
    else {
        cout<<year<<" is not a Leap Year"<<endl;
    }
    return 0;
}

// Enter the year : 2000
// 2000 is a Leap Year

// Enter the year : 2100
// 2100 is not a Leap Year

// Enter the year : 2016
// 2016 is a Leap Year

// Enter the year : 1973
// 1973 is not a Leap Year