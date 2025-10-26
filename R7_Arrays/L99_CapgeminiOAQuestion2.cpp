// Capgemini OA Coding Question 2

// Test case 1
// n = 5, p = 2, K = 18
// cost[] = [6,2,1,10,8]
// reward[] = [10,5,8,26,14]

// ans = 36

// Test case 2
// n = 5, p = 1, K = 0
// cost[] = [0,0,0,0,0]
// reward[] = [5,2,3,8,4]

// ans = 12

// Brute Force Solution 
// T.C. = O(N^2)
// S.C. = O(1)
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;   
    cout<<"Enter n : ";   cin>>n;
    int p;   
    cout<<"Enter p : ";   cin>>p;
    int K;   
    cout<<"Enter K : ";   cin>>K;

    int* cost = new int[n];
    cout<<"Enter elements of cost array : ";
    for(int i = 0 ; i < n ; i++) {
        cin>>cost[i];
    }

    int* reward = new int[n];
    cout<<"Enter elements of reward array : ";
    for(int i = 0 ; i < n ; i++) {
        cin>>reward[i];
    }

    int maxProfit = 0;
    
    // Try all possible starting positions
    for (int start = 0 ; start < n ; start++) {

        int current = start;
        int totalCost = cost[start];
        int totalReward = reward[start];
        
        if(totalCost <= K) {
            maxProfit = max(maxProfit, totalReward);
        }
        
        // Continue jumping with step p+1
        while(current+p+1 < n) {

            current = current+p+1;
            totalCost += cost[current];
            totalReward += reward[current];
            
            if(totalCost <= K) {
                maxProfit = max(maxProfit, totalReward);
            } 
            else {
                break; // Can't afford more
            }
        }
    }
    
    cout<<"Maximum profit : "<<maxProfit<<endl;
    return 0;
}

// Enter n : 5
// Enter p : 2
// Enter K : 18
// Enter elements of cost array : 6 2 1 10 8
// Enter elements of reward array : 10 5 8 26 14
// Maximum profit : 36

// Enter n : 5
// Enter p : 1
// Enter K : 0
// Enter elements of cost array : 0 0 0 0 0
// Enter elements of reward array : 5 2 3 8 4
// Maximum profit : 12

