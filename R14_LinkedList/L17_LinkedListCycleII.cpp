// Leetcode : 142
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

bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            return true;
        }
    }
    return false;
}

ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    bool flag = false; // no cycle
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            flag = true;
            break;
        }
    }
    if(flag == false) {
        return NULL;
    }
    else {
        ListNode* temp = head;
        while(temp != slow) {
            slow = slow->next;
            temp = temp->next;
        }
        return slow;
    }
}

int main()
{
    return 0;
}