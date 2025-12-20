#include <iostream>
using namespace std;

int sumOfN(int arr[], int n, int sum) {
    if(n == 1) {
        return arr[n-1];
    }
    sum = (arr[n-1] + sumOfN(arr,n-1,sum));
    return sum;
}
int main()
{
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans = sumOfN(arr,n,0); 
    cout<<ans<<endl; // 15
    return 0;
}