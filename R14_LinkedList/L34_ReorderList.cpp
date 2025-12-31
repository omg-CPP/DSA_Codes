// Leetcode 143
#include <iostream>
using namespace std;

class ListNode {
public : 
    int val;
    ListNode* next;
    // Constructor
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

ListNode* reverseList(ListNode* head) {
    ListNode* Prev = NULL;
    ListNode* Curr = head;
    ListNode* Next = NULL;

    while(Curr != NULL) {
        Next = Curr->next;
        Curr->next = Prev;
        Prev = Curr;
        Curr = Next;
    }
    return Prev;
}

void reorderList(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // slow is at the left middle / middle
    ListNode* b = reverseList(slow->next);
    ListNode* a = head;
    slow->next = NULL; // for breaking the list

    // merge these 2 list a and b alternatively
    ListNode* c = new ListNode(100);
    ListNode* tempC = c;
    ListNode* tempA = a;
    ListNode* tempB = b;
    
    while(tempA != NULL && tempB != NULL) {
        tempC->next = tempA;
        tempA = tempA->next;
        tempC = tempC->next;

        tempC->next = tempB;
        tempB = tempB->next;
        tempC = tempC->next;
    }
    tempC->next = tempA;
    head = c->next;
}

int main()
{
    return 0;
}