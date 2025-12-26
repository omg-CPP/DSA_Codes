#include <iostream>
using namespace std;
int main()
{
    // In a singly linked list, deletion of data requires modification of how many pointers?

    // 1
    // 2
    // 3
    // Depends upon the node being deleted.
    // Answer
    // option 1

    // If you have
    // A → B → C
    // and you want to delete B,
    // you just set
    // A.next = C

    // So, only 1 pointer modification is needed.

    // suppose temp has to be deleted
    // prev node is before temp

    // prev->next = temp->next
    // delete temp

    // So, 2 pointers modification is needed.
    return 0;
}