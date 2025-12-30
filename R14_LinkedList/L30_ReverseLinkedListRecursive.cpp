// Leetcode : 206

#include <iostream>
using namespace std;

class ListNode {
public :
    int val;
    ListNode* next;

    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

ListNode* reverseList(ListNode* head) {
    // Recursive Approach To Reverse a Linked List
    // base case 
    if(head == NULL || head->next == NULL) {
        return head;
    }
    ListNode* newNode = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newNode;
}

int main()
{
    
    return 0;
}