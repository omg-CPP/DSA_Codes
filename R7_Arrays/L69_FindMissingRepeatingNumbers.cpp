#include <iostream>
#include <vector>
using namespace std;

// Array has number 1 to n
vector<int> findMissingRepeatingNumberBruteForce(vector<int>& nums) {
    // Time Complexity : O(n^2)
    int n = nums.size();
    int repeating = -1;
    int missing = -1;
    // arr = {4,3,6,2,1,1}
    for(int i = 1 ; i <= n ; i++) {
        int count = 0;
        for(int j = 0 ; j < n ; j++) {
            if(nums[j] == i) {
                count++;
            }
        }
        if(count == 2) {
            repeating = i;
        }
        else if(count == 0) {
            missing = i;
        }
        // If you got both the values
        if(repeating != -1 && missing != -1) {
            break;
        }
    }
    return {repeating,missing};
}

vector<int> findMissingRepeatingNumber(vector<int>& nums) {
    // Time Complexity : O(n)
    // Space Complexity : O(1)
    long long n = nums.size();
    // S - Sn
    // S2 - S2n
    long long SN = (n * (n+1)) / 2;
    long long S2N = (n * (n+1) * (2*n+1)) / 6;
    long long S = 0;
    long long S2 = 0;
    for(int i = 0 ; i < n ; i++) {
        S = S + (long long)nums[i];
        S2 = S2 + ((long long)nums[i] * (long long)nums[i]);
    }
    // x -> repeating
    // y -> missing
    long long first = S - SN; // repeating - missing => x - y
    long long second = S2 - S2N; // repeating^2 - missing^2  =>  x^2 - y^2
    second = second / first; // x + y
    long long x = (first + second) / 2;
    long long y = x - first; // y = x - (x - y)

    return {(int)x, (int)y};
}
int main()
{
    vector<int> arr = {4,3,6,2,1,1};

    vector<int> res = findMissingRepeatingNumberBruteForce(arr);
    cout<<res[0]<<" is the Repeating Number"<<endl;
    // 1 is the Repeating Number
    cout<<res[1]<<" is the Missing Number"<<endl;
    // 5 is the Missing Number

    vector<int> ans = findMissingRepeatingNumber(arr);
    cout<<ans[0]<<" is the Repeating Number"<<endl;
    // 1 is the Repeating Number
    cout<<ans[1]<<" is the Missing Number"<<endl;
    // 5 is the Missing Number
    return 0;
}
