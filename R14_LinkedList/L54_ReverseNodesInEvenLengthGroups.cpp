// Leetcode : 2074

#include <iostream>
using namespace std;

class ListNode {
public:
    int val;   
    ListNode* next;
    // Constructor
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void display(ListNode* head) {
    while(head != NULL) {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

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

ListNode* reverseBetween(ListNode* head, int left, int right) {
    // 1-Based Indexing
    if(left == right) {
        return head;
    }
    ListNode* a = NULL;
    ListNode* b = NULL;
    ListNode* c = NULL;
    ListNode* d = NULL;
    ListNode* temp = head;

    int n = 1;
    while(temp != NULL) {
        if(n == left-1) {
            a = temp;
        }
        if(n == left) {
            b = temp;
        }
        if(n == right) {
            c = temp;
        }
        if(n == right+1) {
            d = temp;
        }
        temp = temp->next;
        n++;
    }
    if(a != NULL) {
        a->next = NULL;
    }
    c->next = NULL;
    c = reverseList(b);
    if(a != NULL) {
        a->next = c;
    }
    b->next = d;
    if(a != NULL) {
        return head;
    }
    else {
        return c;
    }
}

ListNode* reverseAllLengthGroups(ListNode* head) {
    ListNode* temp = head;
    int gap = 1;
    while(temp->next != NULL) {
        reverseBetween(temp,2,gap+2);
        gap++;
        for(int i = 1 ; i <= gap ; i++) {
            temp = temp->next;
        }
    }
    return head;
}

ListNode* reverseEvenLengthGroups(ListNode* head) {
    // even length = odd gap
    ListNode* temp = head;
    int gap = 1;
    while(temp != NULL && temp->next != NULL) {
        int remLen = 0;
        ListNode* t = temp->next;
        for(int i = 1 ; i <= gap+1 && t != NULL ; i++) {
            t = t->next;
            remLen++;
        }
        if(remLen < gap+1) {
            gap = remLen-1;
        }
        if(gap % 2 != 0) {
            reverseBetween(temp,2,gap+2);
        }
        gap++;
        for(int i = 1 ; temp != NULL && i <= gap ; i++) {
            temp = temp->next;
        }
    }
    return head;
}

int main()
{
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(4);
    ListNode* e = new ListNode(5);
    ListNode* f = new ListNode(6);
    ListNode* g = new ListNode(7);
    ListNode* h = new ListNode(8);
    ListNode* i = new ListNode(9);
    ListNode* j = new ListNode(10);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g;
    g->next = h;
    h->next = i;
    i->next = j;

    display(a);
    // 1 2 3 4 5 6 7 8 9 10 
    cout<<a<<endl;

    
    a = reverseAllLengthGroups(a);
    
    display(a);
    // 1 3 2 6 5 4 10 9 8 7 
    return 0;
}