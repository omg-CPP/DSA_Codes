// In the Tower of Hanoi puzzle, you are given n disks stacked in ascending order (smallest at the top) on the first of three rods. The goal is to move all disks to the third rod following two rules: only one disk can be moved at a time, and a disk can only be placed on top of a larger disk. Given the number of disks n and three rods labeled as from, to, and aux (starting rod, target rod, and auxiliary rod, respectively),  returns the total number of moves needed to transfer all disks from the starting rod to the target rod.

#include <iostream>
using namespace std;

// Recursive Idea : 
// n-1 disks : src -> helper with the help of dest : Recursion
// Biggest disk : print src -> dest
// n-1 disks : helper -> dest with the help of src : Recursion
int moves = 0; // global variable

void towerOfHanoi(int n, char src, char helper, char dest) {
    // base case 
    if(n == 0) {
        return;
    }
    towerOfHanoi(n-1,src,dest,helper);
    cout<<src<<" -> "<<dest<<endl;
    moves++;
    towerOfHanoi(n-1,helper,src,dest);
}

int main()
{
    int n;
    cout<<"Enter number of disks : ";
    cin>>n;
    towerOfHanoi(n,'A','B','C');
    cout<<moves<<" moves are taken to solve this "<<n<<" disk problem"<<endl;
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
// 7 moves are taken to solve this 3 disk problem

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
// 15 moves are taken to solve this 4 disk problem