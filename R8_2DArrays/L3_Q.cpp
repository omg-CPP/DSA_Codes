// To store roll no and marks of 4 students
#include <iostream>
using namespace std;
int main()
{
    int arr[2][4];
    cout<<"Enter Roll No and Marks : "<<endl;
    for(int i = 0 ; i <= 1 ; i++) {
        for(int j = 0 ; j <= 3 ; j++) {
            cin>>arr[i][j];
        }
    }

    cout<<"Row Representation"<<endl;
    for(int i = 0 ; i <= 1 ; i++) {
        for(int j = 0 ; j <= 3 ; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    // Enter Roll No and Marks : 
    // 1 2 3 4
    // 8 9 7 5
    // Row Representation
    // 1 2 3 4 
    // 8 9 7 5 

    int brr[4][2];
    cout<<"Enter Roll No and Marks : "<<endl;
    for(int i = 0 ; i <= 3 ; i++) {
        for(int j = 0 ; j <= 1 ; j++) {
            cin>>brr[i][j];
        }
    }

    cout<<"Column Representation"<<endl;
    for(int i = 0 ; i <= 3 ; i++) {
        for(int j = 0 ; j <= 1 ; j++) {
            cout<<brr[i][j]<<" ";
        }
        cout<<endl;
    }

    // Enter Roll No and Marks : 
    // 1 8
    // 2 9
    // 3 7
    // 4 5
    // Column Representation
    // 1 8 
    // 2 9 
    // 3 7 
    // 4 5 
    return 0;
}

