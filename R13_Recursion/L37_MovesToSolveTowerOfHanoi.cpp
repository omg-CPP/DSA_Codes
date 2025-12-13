#include <iostream>
using namespace std;

int towerOfHanoi(int n, char src, char helper, char dest) {
    // base case 
    int moves = 0;
    if(n == 0) {
        return 0;
    }
    moves += towerOfHanoi(n-1,src,dest,helper);
    cout<<src<<" -> "<<dest<<endl;
    moves++;
    moves += towerOfHanoi(n-1,helper,src,dest);
    return moves;
}

int main()
{
    int n;
    cout<<"Enter number of disks : ";
    cin>>n;
    int moves = towerOfHanoi(n,'A','B','C');
    cout<<moves<<endl;
    return 0;
}

// Enter number of disks : 3
// A -> C
// A -> B
// C -> B
// A -> C
// B -> A
// B -> C
// A -> C
// 7

// Enter number of disks : 4
// A -> B
// A -> C
// B -> C
// A -> B
// C -> A
// C -> B
// A -> B
// A -> C
// B -> C
// B -> A
// C -> A
// B -> C
// A -> B
// A -> C
// B -> C
// 15