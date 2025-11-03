#include <iostream>
using namespace std;

// works perfectly
void change1D(int a[]) {
    a[0] = 9;
}

// shows error because of not giving size in 2D array

// void change2D(int arr[][]) {
//     arr[0][0] = 9;
// }

// works perfectly
// size has to be defined in 2D array

void change2D(int arr[3][3]) {
    arr[0][0] = 9;
}

int main()
{
    int a[3] = {1,2,3};
    cout<<a[0]<<endl; // 1
    change1D(a);
    cout<<a[0]<<endl; // 9

    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    cout<<arr[0][0]<<endl; // 1
    change2D(arr);
    cout<<arr[0][0]<<endl; // 9
    return 0;
}