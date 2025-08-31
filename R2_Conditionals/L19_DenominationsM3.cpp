#include <iostream>
using namespace std;

int main() {
    int amount;
    cout<<"Enter amount : ";
    cin>>amount;

    int denominations[] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    int numNotes[10] = {0}; // initially all set to 0

    for(int i = 0 ; i < 10 ; i++) {
        cout<<numNotes[i]<<" ";
    }
    // 0 0 0 0 0 0 0 0 0 0 
    cout<<endl;

    // Number of denominations
    int n = sizeof(denominations)/sizeof(denominations[0]);

    // Calculate number of notes for each denomination
    for(int i = 0 ; i < n ; i++) {
        if(amount >= denominations[i]) {
            numNotes[i] = amount/denominations[i];
            amount -= numNotes[i]*denominations[i];
        }
    }

    // Display the result
    cout<<"\nNotes Distribution : \n";
    for(int i = 0 ; i < n ; i++) {
        cout<<denominations[i]<<" notes : "<<numNotes[i]<<endl;
    }

    return 0;
}


// Enter amount : 3888
// 0 0 0 0 0 0 0 0 0 0 

// Notes Distribution : 
// 2000 notes : 1
// 500 notes : 3
// 200 notes : 1
// 100 notes : 1
// 50 notes : 1
// 20 notes : 1
// 10 notes : 1
// 5 notes : 1
// 2 notes : 1
// 1 notes : 1