// Leetcode : 92
// Reverse Part of the Linked List
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

ListNode* reverseBetween(ListNode* head, int left, int right) {
    // 1-Based Indexing
    if(left == right) {
        return head;
    }
    ListNode* a = NULL;
    ListNode* b = NULL;
    ListNode* c = NULL;
    ListNode* d = NULL;
    ListNode* temp = head;

    int n = 1;
    while(temp != NULL) {
        if(n == left-1) {
            a = temp;
        }
        if(n == left) {
            b = temp;
        }
        if(n == right) {
            c = temp;
        }
        if(n == right+1) {
            d = temp;
        }
        temp = temp->next;
        n++;
    }
    if(a != NULL) {
        a->next = NULL;
    }
    c->next = NULL;
    c = reverseList(b);
    if(a != NULL) {
        a->next = c;
    }
    b->next = d;
    if(a != NULL) {
        return head;
    }
    else {
        return c;
    }
}

int main()
{
    return 0;
}