// Leetcode : 445
// Using Stack Data Structure
// Addition will be done from right side or from least significant digit

#include <iostream>
#include <stack>
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

// M1 : Reverse LinkedList Approach
ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* Next = NULL;
    while(curr != NULL) {
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
    }
    return prev;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    l1 = reverseList(l1);
    l2 = reverseList(l2);

    ListNode* head = NULL;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
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
        newNode->next = head;
        head = newNode;
    }
    return head;
}


// M2 : Stack Approach
void fillStack(ListNode* list, stack<int>& stack) {
    ListNode* temp = list;
    while(temp != NULL) {
        stack.push(temp->val);
        temp = temp->next;
    }
}

ListNode* addTwoNumbersM2(ListNode* l1, ListNode* l2) {
    stack<int> st;
    fillStack(l1,st);
    stack<int> gt;
    fillStack(l2,gt);

    int carry = 0;
    ListNode* head = NULL;
    while(l1 != NULL || l2 != NULL || carry != 0) {
        int sum = 0;
        if(st.size() != 0) {
            sum = sum + st.top();
            st.pop();
        }
        if(gt.size() != 0) {
            sum = sum + gt.top();
            gt.pop();
        }
        sum = sum + carry;
        carry = sum/10;
        ListNode* newNode = new ListNode(sum%10);
        newNode->next = head;
        head = newNode;
    }
    return head;
}

int main()
{
    return 0;
}