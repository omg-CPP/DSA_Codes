// Leetcode : 2

// 0 <= Node.val <= 9

// Integers are stored in rev order
// so we know unit digit is placed first so we can simply add from the left side
// T.C. = O(max(len(l1,l2)))
// S.C. = O(n)

#include <iostream>
using namespace std;

class ListNode {
public:
    int val;   
    ListNode* next;

    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* tempD = dummy;
    int carry = 0;
    while(l1 != NULL || l2 != NULL || carry != 0) {
        int sum = 0;
        if(l1 != NULL) {
            sum = sum + l1->val;
            l1 = l1->next;
        }
        if(l2 != NULL) {
            sum = sum + l2->val;
            l2 = l2->next;
        }
        sum = sum + carry;
        carry = sum/10;
        ListNode* newNode = new ListNode(sum%10);
        tempD->next = newNode;
        tempD = tempD->next;
    }
    return dummy->next;
}

int main()
{
    return 0;
}