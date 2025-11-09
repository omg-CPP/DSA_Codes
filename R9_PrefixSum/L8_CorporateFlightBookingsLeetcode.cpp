#include <iostream>
#include <vector>
using namespace std;

// Time Complexity : O(k+n) 
// k : no of bookingd
// n : no of flights

// Logic : 
// ans = [0,0,0,0,0]

// B1 : [1,2,10]
// ans = [10,0,-10,0,0]

// B2 : [2,3,20]
// ans = [10,20,-10,-20,0]

// B3 : [2,5,25]
// ans = [10,45,-10,-20,0]

// prefix sum ans[] = [10,55,45,25,25]

vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    // n : no of flights
    // creating a ans array with initially 0 value
    vector<int> ans(n,0);

    // Apply difference array logic
    for(int i = 0 ; i < bookings.size() ; i++) {
        int first = bookings[i][0];
        int last = bookings[i][1];
        int seats = bookings[i][2];

        // Add seats at start index
        // According to 0-based indexing of array
        ans[first-1] += seats;

        // Subtract seats after the end index if within bounds
        // According to 0-based indexing of array
        if(last < n) {
            ans[last] -= seats;
        }
    }

    // calculating prefix sum array
    for(int i = 1 ; i < n ; i++) {
        ans[i] = ans[i-1] + ans[i];
    }

    return ans;
}
int main()
{
    // Sample bookings input
    vector<vector<int>> bookings = {{1,2,10},{2,3,20},{2,5,25}};
    int n = 5;
    // Call the function
    vector<int> result = corpFlightBookings(bookings,n);
    // Print the result using for loop
    cout<<"Total seats booked on each flight : "<<endl;
    for(int i = 0 ; i < result.size() ; i++) {
        cout<<"Flight "<<(i+1)<<" : "<<result[i]<<" seats"<<endl;
    }
    return 0;
}

// Total seats booked on each flight : 
// Flight 1 : 10 seats
// Flight 2 : 55 seats
// Flight 3 : 45 seats
// Flight 4 : 25 seats
// Flight 5 : 25 seats