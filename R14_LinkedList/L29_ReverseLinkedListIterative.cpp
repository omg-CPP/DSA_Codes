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

void display(ListNode* head) {
    ListNode* temp = head;
    while(temp != NULL) {
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// Three Pointers : Optimal Iterative Code
// T.C. = O(n)
// S.C. = O(1)
ListNode* reverseList(ListNode* head) {
    ListNode* Prev = NULL;
    ListNode* Curr = head;
    ListNode* Next = NULL;

    while(Curr != NULL) {
        Next = Curr->next;
        Curr->next = Prev;
        Prev = Curr;
        Curr = Next;
    }
    return Prev;
}

int main()
{

    return 0;
}