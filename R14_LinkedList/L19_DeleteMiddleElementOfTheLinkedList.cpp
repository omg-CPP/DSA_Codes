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

ListNode* deleteMiddle(ListNode* head) {
    // single element case
    if(head->next == NULL) {
        return NULL;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    // check first if fast != NULL before fast->next != NULL
    // Because it will give NULL Pointer Exception
    // If first condition is false -> it will not check 2nd condn
    while(fast->next->next != NULL && fast->next->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = slow->next->next;
    return head;
}

int main()
{
    ListNode* A = new ListNode(10);
    ListNode* B = new ListNode(20);
    ListNode* C = new ListNode(30);
    ListNode* D = new ListNode(40);
    ListNode* E = new ListNode(50);
    ListNode* F = new ListNode(60);

    A->next = B;
    B->next = C;
    C->next = D;
    D->next = E;
    E->next = F;

    ListNode* temp = A;
    while(temp != NULL) {
        cout<<temp->value<<" ";
        temp = temp->next;
    }
    cout<<endl;
    // 10 20 30 40 50 60 

    ListNode* head = A;
    head = deleteMiddle(head);

    while(A != NULL) {
        cout<<A->value<<" ";
        A = A->next;
    }
    cout<<endl;
    // 10 20 30 50 60 
    return 0;
}