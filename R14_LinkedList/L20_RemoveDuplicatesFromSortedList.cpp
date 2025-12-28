// Leetcode : 83

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

ListNode* deleteDuplicates(ListNode* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    ListNode* a = head;
    ListNode* b = head->next;
    while(b != NULL) {
        while(b != NULL && b->value == a->value) {
            b = b->next;
        }
        a->next = b;
        // for next round
        a = b;
        if(b != NULL) {
            b = b->next;
        }
    }
    return head;
}

int main()
{
    return 0;
}