// Leetcode : 1721
#include <iostream>
using namespace std;
// Swapping of only values has taken place
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

ListNode* swapNodes(ListNode* head, int k) {
    int n = 0;
    ListNode* temp = head;
    while(temp != NULL) {
        temp = temp->next;
        n++;
    }
    ListNode* a = head;
    for(int i = 1 ; i <= k-1 ; i++) {
        a = a->next;
    }
    ListNode* b = head;
    for(int i = 1 ; i <= n-k ; i++) {
        b = b->next;
    }
    int t = a->val;
    a->val = b->val;
    b->val = t;
    return head;
}

int main()
{
    return 0;
}