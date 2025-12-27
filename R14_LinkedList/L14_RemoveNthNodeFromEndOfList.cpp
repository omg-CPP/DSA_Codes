// Leetcode : 19
// Given the head of a linked list, remove the nth node from the end of the list and return its head.
// n -> 1 onwards
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

ListNode* removeNthFromEnd(ListNode* head, int n) {
    // n is given from end of the list
    // nth node from end = (len-n+1)th node from start
    int len = 0;
    ListNode* temp = head;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    if(n == len) {
        head = head->next;
        return head;
    }
    int m = len-n+1;
    int idx = m-1;
    temp = head;
    for(int i = 1 ; i <= idx-1 ; i++) {
        temp = temp->next;
    }
    temp->next = temp->next->next;
    return head;
}

ListNode* removeNthFromEnd2(ListNode* head, int n) {
    // Using slow and fast pointer
    ListNode* slow = head;
    ListNode* fast = head;
    // Move fast pointer n+1 steps forward
    for(int i = 1 ; i <= n+1 ; i++) {
        if(fast == NULL) {
            return head->next;
        }
        fast = fast->next;
    }
    // Move both slow and fast pointers one-one step forward until fast == NULL
    while(fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return slow;
}

int main()
{
    return 0;
}