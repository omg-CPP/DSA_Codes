// Leetcode : 21
#include <iostream>
using namespace std;

class ListNode {
public :
    int value;
    ListNode* next;

    ListNode(int value) {
        this->value = value;
        this->next = NULL;
    }
};

// With O(m+n) extra Space
ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
    ListNode* tempA = a;
    ListNode* tempB = b;
    ListNode* c = new ListNode(100);
    ListNode* tempC = c;
    while(tempA != NULL && tempB != NULL) {
        if(tempA->value <= tempB->value) {
            ListNode* t = new ListNode(tempA->value);
            tempC->next = t;
            tempC = t;
            tempA = tempA->next;
        }
        else {
            ListNode* t = new ListNode(tempB->value);
            tempC->next = t;
            tempC = t;
            tempB = tempB->next;
        }
    }
    if(tempA == NULL) {
        tempC->next = tempB;
    }
    else { // tempB == NULL
        tempC->next = tempA;
    }
    return c->next;
}

// Without Extra Space
ListNode* mergeTwoLists2(ListNode* a, ListNode* b) {
    ListNode* c = new ListNode(100);
    ListNode* temp = c;
    while(a != NULL && b != NULL) {
        if(a->value <= b->value) {
            temp->next = a;
            a = a->next;
            temp = temp->next;
        }
        else { // a->value > b->value
            temp->next = b;
            b = b->next;
            temp = temp->next;
        }
    }
    if(a == NULL) {
        temp->next = b;
    }
    else { // b == NULL
        temp->next = a;
    }
    return c->next;
}

int main()
{
    return 0;
}