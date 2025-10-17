#include <iostream>
using namespace std;
int main()
{
    int arr[5]={1,2,2,4,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0 ; i < n ; i++) {
        int j;
        for(j = 0 ; j < n ; j++) {
            if(i != j && arr[i] == arr[j]) {
                break;
            }
        }
        if(j == n) {
            cout<<arr[i]; // 1
            return 0;
        }
    }
    return 0;
}