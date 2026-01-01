// Leetcode : 328

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

ListNode* oddEvenList(ListNode* head) {
    ListNode* odd = new ListNode(0);
    ListNode* even = new ListNode(0);

    ListNode* tempOdd = odd;
    ListNode* tempEven = even;

    ListNode* temp = head;

    while(temp != NULL) {
        tempOdd->next = temp;
        temp = temp->next;
        tempOdd = tempOdd->next;

        tempEven->next = temp;
        if(temp == NULL) {
            break;
        }
        tempEven = tempEven->next;
    }
    odd = odd->next;
    even = even->next;
    tempOdd->next = even;
    return odd;
}

int main()
{
    return 0;
}