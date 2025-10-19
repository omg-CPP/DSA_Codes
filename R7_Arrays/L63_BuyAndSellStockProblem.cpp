#include <iostream>
#include <vector> 
using namespace std;

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
    vector<int> prices = {7,1,5,3,6,4};
    int profit = maxProfit(prices);
    cout<<profit<<endl; // 5
    return 0;
}