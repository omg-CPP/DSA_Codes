// GFG : Stock Span Problem
// span : maximum no of consecutive days from today for which prices <= todays's price including current day price

// previous greater element is being calculated for each day
// immediate greater value = previous greater value
// span for each day = ith index - previous greater value index

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// T.C. = O(n) + O(n) = O(2n) 
// S.C. = O(n) + O(n) = O(2n)

// Concept of previous greater element index is applied
vector<int> calculateSpan(vector<int>& arr) {
    int n = arr.size();
    stack<int> st;
    vector<int> span(n);
    for(int i = 0 ; i < n ; i++) {
        while(st.size() > 0 && arr[st.top()] <= arr[i]) {
            st.pop();
        }
        if(st.size() == 0) {
            span[i] = i - (-1);
        }
        else {
            span[i] = i - st.top();
        }
        st.push(i);
    }
    return span;
}

int main()
{
    vector<int> stocks = {100,80,60,70,60,75,85};
    vector<int> span = calculateSpan(stocks);
    for(int i = 0 ; i < span.size() ; i++) {
        cout<<span[i]<<" ";
    }
    // 1 1 1 2 1 4 6 
    cout<<endl;
    return 0;
}