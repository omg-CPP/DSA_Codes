// Leetcode : 121

#include <iostream>
#include <vector>
using namespace std;

// maximum profit is maintained while changing the bestBuy
// 7 3 8 2 6 5

// T.C. = O(N)
// S.C. = O(1)
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int maxProfit = 0;
    int bestBuy = prices[0];
    // selling day will start from day 1
    for(int i = 1 ; i < n ; i++) {
        if(prices[i] > bestBuy) {
            maxProfit = max(maxProfit, prices[i]-bestBuy);
        }
        bestBuy = min(bestBuy, prices[i]);
    }
    return maxProfit;
}


int main()
{
    vector<int> prices = {7,3,8,2,6,5};
    cout<<maxProfit(prices)<<endl; // 5
    return 0;
}
