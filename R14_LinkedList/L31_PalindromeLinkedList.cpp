// Leetcode : 234
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

bool isPalindrome(ListNode* head) {
    // Deep Copy : S.C. = O(n) and T.C. = O(n)
    ListNode* c = new ListNode(10);
    ListNode* temp = head;
    ListNode* tempC = c;
    while(temp != NULL) {
        ListNode* node = new ListNode(temp->val);
        tempC->next = node;
        temp = temp->next;
        tempC = tempC->next;
    }
    c = c->next;
    c = reverseList(c);
    ListNode* a = head;
    ListNode* b = c;
    while(a != NULL) {
        if(a->val != b->val) {
            return false;
        }
        a = a->next;
        b = b->next;
    }
    return true;
}

bool isPalindromeOptimal(ListNode* head) {
    // T.C. = O(n)
    // S.C. = O(1)
    // if the first half and seconf half are reverse of each other 
    // than they are palindrome 
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // slow is at the left middle for even and at middle for odd
    ListNode* right = reverseList(slow->next);
    slow->next = right; // connecting slow with the reversed LinkedList head which is right which was earlier connected to last element of the reversed linked list...
    ListNode* a = head;
    ListNode* b = right;
    while(b != NULL) {
        if(a->val != b->val) {
            return false;
        }
        a = a->next;
        b = b->next;
    }
    return true;
}

int main()
{
    return 0;
}