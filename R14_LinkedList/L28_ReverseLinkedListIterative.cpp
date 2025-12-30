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

ListNode* getNodeAt(ListNode* head, int idx) {
    ListNode* temp = head;
    for(int i = 1 ; i <= idx ; i++) {
        temp = temp->next;
    }
    return temp;
}

ListNode* reverseListBruteForce(ListNode* head) {
    // Two Pointers Array Approach
    int n = 0;
    ListNode* temp = head;
    while(temp != NULL) { // while(temp)
        temp = temp->next;
        n++;
    }
    int i = 0;
    int j = n-1;
    while(i < j) {
        ListNode* l = getNodeAt(head,i);
        ListNode* r = getNodeAt(head,j);
        int t = l->val;
        l->val = r->val;
        r->val = t;
        i++;
        j--;
    }
    return head;
}

int main()
{
    ListNode* a = new ListNode(10);
    ListNode* b = new ListNode(20);
    ListNode* c = new ListNode(30);
    ListNode* d = new ListNode(40);
    ListNode* e = new ListNode(50);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;


    cout<<a<<endl; // 0x10c18f8
    cout<<"Original List : ";
    display(a); // Original List : 10 20 30 40 50
    cout<<a<<endl; // 0x10c18f8

    ListNode* reversedHead = reverseListBruteForce(a);
    cout<<"Reversed Linked List : ";
    display(reversedHead); // Reversed Linked List : 50 40 30 20 10 
    cout<<a<<endl; // 0x10c18f8
    cout<<reversedHead<<endl; // 0x10c18f8
    display(a); // 50 40 30 20 10
    return 0;
}