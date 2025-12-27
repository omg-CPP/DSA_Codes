// Leetcode : 160
// Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

#include <iostream>
using namespace std;

class ListNode { // Linked List Node
    public :
    int value;
    ListNode* next;
    // Constructor
    ListNode(int value) {
        this->value = value;
        this->next = NULL;
    }
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    // find the length of both the linked lists
    ListNode* tempA = headA;
    ListNode* tempB = headB;

    int lenA = 0;
    while(tempA != NULL) {
        lenA++;
        tempA = tempA->next;
    }

    int lenB = 0;
    while(tempB != NULL) {
        lenB++;
        tempB = tempB->next;
    }

    tempA = headA;
    tempB = headB;

    if(lenA > lenB) { // List A is bigger
        int diff = lenA - lenB;
        for(int i = 1 ; i <= diff ; i++) {
            tempA = tempA->next;
        }
        while(tempA != tempB) {
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return tempA;
    }
    else { // lenA <= lenB
        int diff = lenB - lenA;
        for(int i = 1 ; i <= diff ; i++) {
            tempB = tempB->next;
        }
        while(tempA != tempB) {
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return tempA;
    }
}

int main()
{
    return 0;
}