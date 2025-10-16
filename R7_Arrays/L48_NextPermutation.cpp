#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void displayVector(vector<int>& a) {
    for(int i = 0 ; i < a.size() ; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return;
}

void reversePart(vector<int>& nums, int i, int j) {
    while(i < j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        i++;
        j--;
    }
    return;
}
void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    // finding pivot index
    int pivot_idx = -1;
    for(int i = n-2 ; i >= 0 ; i--) {
        if(nums[i] < nums[i+1]) {
            pivot_idx = i;
            break;
        }
    }

    // if already array is greatest
    if(pivot_idx == -1) {
        // reversePart(nums,0,n-1);
        // inbuilt reverse in vector
        reverse(nums.begin(),nums.end());
        return;
    }

    // sorting/reverse after pivot
    // reverse(nums.begin()+(pivot_idx+1), nums.begin()+(n-1)+1);
    reverse(nums.begin()+(pivot_idx+1), nums.end());
    // reversePart(nums,pivot_idx+1,n-1);

    // finding just greater element than pivot_idx
    int j = -1;
    for(int i = pivot_idx+1 ; i < n ; i++) {
        if(nums[i] > nums[pivot_idx]) {
            j = i;
            break;
        }
    }

    // swapping pivot_idx and pivot_idx+1
    int temp = nums[pivot_idx];
    nums[pivot_idx] = nums[j];
    nums[j] = temp;
    return;
}
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);
    v.push_back(2);

    displayVector(v); // 1 4 3 2 

    nextPermutation(v);

    displayVector(v); // 2 1 3 4 

    return 0;
}