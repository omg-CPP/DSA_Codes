// Array contains both positive and negative elements
// Array is sorted
#include <iostream>
using namespace std;
int main()
{
    int arr[] = {-8,-2,0,1,2,4,5};
    // int arr[] = {-4,-3,-2,0,1,2,3,4,6,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    bool flag = false;
    int x = 1;

    for(int i = 0 ; i < n ; i++) {
        if(arr[i] <= 0) {
            continue;
        }

        if(x != arr[i]) {
            cout<<x<<" is the smallest missing positive element"<<endl;
            flag = true;
            break;
        }
        else {
            x++;
        }
    }

    if(flag == false) {
        cout<<"No missing positive element"<<endl;
    }
    return 0;
}

// int arr[] = {-8,-2,0,1,2,4,5};
// 3 is the smallest missing positive element

// int arr[] = {-4,-3,-2,0,1,2,3,4,6,8,9};
// 5 is the smallest missing positive element