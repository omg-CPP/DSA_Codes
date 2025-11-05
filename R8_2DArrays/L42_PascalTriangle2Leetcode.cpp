#include <iostream>
#include <vector>
using namespace std;

vector<int> getRow(int rowIndex) {
    vector<int> ans;
    long long val = 1;
    int i = rowIndex;
    for(int j = 0 ; j <= rowIndex ; j++) {
        ans.push_back(val);
        val = val * (i-j)/(j+1);
    }
    return ans;
}

int main()
{
    int row_idx;
    cout<<"Enter row index : ";
    cin>>row_idx;
    vector<int> res = getRow(row_idx);
    for(int i = 0 ; i < res.size() ; i++) {
        cout<<res[i]<<" ";
    }
    return 0;
}

// Enter row index : 0
// 1 

// Enter row index : 1
// 1 1 

// Enter row index : 2
// 1 2 1 

// Enter row index : 3
// 1 3 3 1 

// Enter row index : 4
// 1 4 6 4 1 

// Enter row index : 5
// 1 5 10 10 5 1 