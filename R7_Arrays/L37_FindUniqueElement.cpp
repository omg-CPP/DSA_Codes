// All the elements in the array are being repeated twice
// only one element is unique

#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1,2,1,4,2,3,4,5,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0 ; i < n ; i++) {
        bool flag = true; // for unique
        for(int j = 0 ; j < n ; j++) {
            if(j == i) {
                continue;
            }
            if(arr[i] == arr[j]) {
                flag = false;
                break;
            }
        }
        if(flag == true) {
            cout<<arr[i]<<endl; // 3
            break;  // as it is given that there is only one unique element in the array
        }
    }
    return 0;
}