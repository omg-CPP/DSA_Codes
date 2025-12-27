// Leetcode : 876

// Given the head of a singly linked list, return the middle node of the linked list.

// If there are two middle nodes, return the second middle node.

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

ListNode* middleNode(ListNode* head) {
    // Odd length LinkedList : One middle
    // Even length LinkedList : Two middles
    int len = 0;
    ListNode* temp = head;
    while(temp != NULL) { // T.C. = O(n)
        // cout<<temp->value<<" ";
        len++;
        temp = temp->next;
    }
    if(len % 2 == 0) {
        // int midIdx1 = (len/2)-1; // Left node is not asked
        int midIdx = len/2;
        ListNode* mid = head;
        for(int i = 1 ; i <= midIdx ; i++) { // Again Traverse
            mid = mid->next;
        }
        return mid;
    }
    else { // len = odd
        int midIdx = len/2;
        ListNode* mid = head;
        for(int i = 1 ; i <= midIdx ; i++) {
            mid = mid->next;
        }
        return mid;
    }
}

// One Pass Solution : Slow and Fast Pointer : Interview Favourite

ListNode* middleNode2(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    // check first if fast != NULL before fast->next != NULL
    // Because it will give NULL Pointer Exception
    // If first condition is false -> it will not check 2nd condn
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* middleNode3(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    // for left middle in even length linkedlist
    while(fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    ListNode* a = new ListNode(10);
    ListNode* b = new ListNode(20);
    ListNode* c = new ListNode(30);
    ListNode* d = new ListNode(40);
    ListNode* e = new ListNode(50);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    ListNode* mid = middleNode(a);
    cout<<mid->value<<endl; // 30
    return 0;
}