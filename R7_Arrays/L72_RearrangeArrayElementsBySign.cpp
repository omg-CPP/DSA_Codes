#include <iostream>
#include <vector>
using namespace std;
// Array with equal positive and negative elements
// array size : n -> always even number
// order should be maintained
// pos and neg should be alternate

// Brute force : Time : O(n) + O(n)
//               Space : O(n/2) + O(n/2) = O(n)

void displayVector(vector<int>& nums) {
    int n = nums.size();
    for(int i = 0 ; i < nums.size() ; i++) {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

vector<int> rearrangeArrayBruteForce(vector<int>& nums) {
    // Time : O(n + n/2)
    // Space : O(n)
    int n = nums.size();
    vector<int> pos;
    vector<int> neg;
    for(int i = 0 ; i < n ; i++) {
        if(nums[i] >= 0) {
            pos.push_back(nums[i]);
        }
        else { // nums[i] < 0
            neg.push_back(nums[i]);
        }
    }
    // Rearranging the array
    // if n = 6 -> loop goes from 0 to 5
    for(int i = 0 ; i < n/2 ; i++) {
        nums[2*i] = pos[i];
        nums[2*i + 1] = neg[i];
    }
    return nums;
}

vector<int> rearrangeArray(vector<int>& nums) {
    // Time : O(n)
    // Space : O(1)
    int n = nums.size();
    vector<int> ans(n,0);
    int posIdx = 0;
    int negIdx = 1;
    for(int i = 0 ; i < n ; i++) {
        if(nums[i] >= 0) {
            ans[posIdx] = nums[i];
            posIdx += 2;
        }
        else { // nums[i] < 0
            ans[negIdx] = nums[i];
            negIdx += 2;
        }
    }
    return ans;
}

// Unequal pos and neg Numbers
// Time Complexity : O(n) + O(min(pos,neg)) + O(left)
// If all pos or all neg => O(min(pos,neg)) + + O(left) = O(0) + O(n)
// If half pos and half neg => O(min(pos,neg)) + + O(left) = O(n/2) + O(0)
// Time : O(n) + O(n) = O(2n)
// Space : O(n)
vector<int> rearrangeArrayFollowUp(vector<int>& nums) {
    int n = nums.size();
    vector<int> pos;
    vector<int> neg;
    for(int i = 0 ; i < n ; i++) {
        if(nums[i] >= 0) {
            pos.push_back(nums[i]);
        }
        else { // nums[i] < 0
            neg.push_back(nums[i]);
        }
    }
    // {3,1,-2,-5,2,-4}
    if(pos.size() > neg.size()) {
        for(int i = 0 ; i < neg.size() ; i++) {
            nums[2*i] = pos[i];
            nums[2*i + 1] = neg[i];
        }
        int idx = neg.size() * 2;
        for(int i = neg.size() ; i < pos.size() ; i++) {
            nums[idx] = pos[i];
            idx++;
        }
    }
    else { // pos.size() <= neg.size()
        for(int i = 0 ; i < pos.size() ; i++) {
            nums[2*i] = pos[i];
            nums[2*i + 1] = neg[i];
        }
        int idx = pos.size() * 2;
        for(int i = pos.size() ; i < neg.size() ; i++) {
            nums[idx] = neg[i];
            idx++;
        }
    }
    return nums;
}

int main()
{
    vector<int> nums = {3,1,-2,-5,2,-4};
    displayVector(nums);
    // 3 1 -2 -5 2 -4 
    vector<int> change = rearrangeArrayBruteForce(nums);
    displayVector(change);
    // 3 -2 1 -5 2 -4 
    vector<int> ans = rearrangeArray(nums);
    displayVector(ans);
    // 3 -2 1 -5 2 -4 

    vector<int> v = {-1,2,3,4,-3,1};
    vector<int> sol = rearrangeArrayFollowUp(v);
    displayVector(sol);
    // 2 -1 3 -3 4 1 
    return 0;
}