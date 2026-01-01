// Leetcode : 203
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

ListNode* removeElements(ListNode* head, int val) {
    // Two pointers
    ListNode* temp = new ListNode(100);
    temp->next = head;

    ListNode* prev = temp;
    ListNode* curr = head;

    while(curr != NULL) {
        if(curr->val == val) {
            prev->next = curr->next;
            curr = prev->next;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }
    ListNode* newHead = temp->next;
    return newHead;
}

int main()
{
    return 0;
}