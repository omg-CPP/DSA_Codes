#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1,2,1,4,2,6,7,9,3,5,6,2,4,6,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<n<<endl; // 15
    // n : size of Array
    return 0;
}