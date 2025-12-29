// Leetcode 61

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


ListNode* rotateRight(ListNode* head, int k) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    // find the length of LL
    int n = 0;
    ListNode* temp = head;
    ListNode* tail = NULL;
    while(temp != NULL) {
        if(temp->next == NULL) {
            tail = temp;
        }
        temp = temp->next;
        n++;
    }
    k = k % n;
    if(k == 0) {
        return head;
    }
    // place temp at (n-k)th position
    temp = head;
    for(int i = 1 ; i < n-k ; i++) {
        temp = temp->next;
    }
    // Rotate Algorithm
    tail->next = head;
    head = temp->next;
    temp->next = NULL;
    return head;
}

// M2 : slow and fast pointers
int main()
{
    return 0;
}