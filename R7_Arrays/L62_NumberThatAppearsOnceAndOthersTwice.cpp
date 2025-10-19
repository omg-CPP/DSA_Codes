#include <iostream>
#include <vector>
using namespace std;
// Single Number
int getSingleElementBruteForce(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int num = arr[i]; 
        int cnt = 0;

        for (int j = 0; j < n; j++) {
            if(arr[j] == num)
                cnt++;
        }
        if(cnt == 1) {
            return num;
        }
    }
    // This line will never execute
    // if the array contains a single element.
    return -1;
}

int getSingleElementOptimal(vector<int>& arr) {
    int n = arr.size();
    int xorr = 0;
    for(int i = 0 ; i < n ; i++) {
        xorr = xorr ^ arr[i];
    }
    return xorr;
}

int main()
{
    // Naive Approach(Brute-force approach): 
    vector<int> arr = {4,1,2,1,2};
    int ans = getSingleElementBruteForce(arr);
    cout<<"The single element is : "<<ans<<endl;
    // The single element is : 4

    // Optimal Approach(Using XOR): 
    int res = getSingleElementOptimal(arr);
    cout<<"The single element is : "<<ans<<endl;
    // The single element is : 4
    return 0;
}