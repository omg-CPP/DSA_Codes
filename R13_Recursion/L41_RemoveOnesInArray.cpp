#include <iostream>
#include <vector>
using namespace std;

void removeOnes(int arr[], vector<int> ans, int idx, int n) {
    if(idx == n) {
        for(int i = 0 ; i < ans.size() ; i++) {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return;
    }

    if(arr[idx] == 1) {
        removeOnes(arr,ans,idx+1,n);
    }
    else {
        ans.push_back(arr[idx]);
        removeOnes(arr,ans,idx+1,n);
    }
}
int main()
{
    int arr[] = {1,2,3,1,1,4,1,7};
    vector<int> ans;
    int n = sizeof(arr)/sizeof(arr[0]);
    removeOnes(arr,ans,0,n); // 2 3 4 7 
    return 0;
}