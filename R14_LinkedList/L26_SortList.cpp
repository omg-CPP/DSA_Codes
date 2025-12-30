// Leetcode 148
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

ListNode* merge(ListNode* a, ListNode* b) {
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

ListNode* sortList(ListNode* head) {
    // merge Sort
    // T.C. = O(nlogn)
    // S.C. = O(1)

    // base case
    if(head == NULL || head->next == NULL) {
        return head;
    }

    // To find the left middle in case of even and middle in case of odd
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // now slow is at left middle
    ListNode* a = head;
    ListNode* b = slow->next;
    slow->next = NULL;

    a = sortList(a);
    b = sortList(b);
    ListNode* c = merge(a,b);
    return c;
}

int main()
{
    return 0;
}