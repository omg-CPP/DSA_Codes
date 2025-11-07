// ram is a loan manager, he is given a loan amount 2d grid of n*n order in which he has loan amounts as entries, he could forgive one of the loan amount, but the condition is the the loan amount should be positive and smallest and return it as ans, but if the loan amount is not unique than return the next smallest positive unique loan amount, take for example grid = {{-1,1,2},{2,3,4},{4,5,6}} the ans is 1 which is the smallest positive unique loan amount, for example grid = {{1,2,3},{1,2,4},{3,4,5}}, so the ans would be which is unique, write a c++ solution brute force than optimise it.

// Time Complexity: O(n²) for counting + O(k log k) for map operations
// Space Complexity: O(k) for storing frequencies

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int waiveLoanAmount(vector<vector<int>>& loan) {
    int n = loan.size();
    map<int,int> frequency; // Use map to maintain sorted order

    // Count frequency of all positive numbers
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            if(loan[i][j] > 0) {
                frequency[loan[i][j]]++;
            }
        }
    }

    // Find smallest positive unique value
    for(auto& entry : frequency) {
        if(entry.second == 1) {
            return entry.first; // First unique in sorted order is smallest
        }
    }
    
    return -1; // No positive values found or no unique positive found
}

int main()
{
    vector<vector<int>> loan1 = {{-1,1,2},{2,3,4},{4,5,6}};
    cout<<waiveLoanAmount(loan1)<<endl; // 1
    vector<vector<int>> loan2 = {{1,2,3},{1,2,4},{3,4,5}}; 
    cout<<waiveLoanAmount(loan2)<<endl; // 5
    vector<vector<int>> loan3 = {{1,1,1},{1,1,1},{1,1,1}};
    cout<<waiveLoanAmount(loan3)<<endl; // -1
    vector<vector<int>> loan4 = {{-1,-2,-3},{-4,-5,-6},{-7,-8,-9}};
    cout<<waiveLoanAmount(loan4)<<endl; // -1
    return 0;
}