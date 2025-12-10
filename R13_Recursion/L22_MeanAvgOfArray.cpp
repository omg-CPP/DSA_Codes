#include <iostream>
using namespace std;

// Mean of first N elements = (Sum of first N-1 elements + N-th element)/N
// Mean of first N-1 elements = (Sum of first N-1 elements)/(N-1)
// Sum of first N-1 elements = (Mean of first N-1 elements)*(N-1)


float findMean(int arr[], int n) {
    // base case
    if(n == 1) {
        return (float)arr[n-1];
    }
    float mean = (float)((findMean(arr,n-1)*(n-1) + arr[n-1])/n);
    return mean;
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int mean = findMean(arr,n);
    cout<<"The Mean is : "<<mean<<endl;
    return 0;
}

// The Mean is : 3