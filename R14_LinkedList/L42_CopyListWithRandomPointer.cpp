// Leetcode : 138

#include <iostream>
using namespace std;

class Node {
public:
    int val;   
    Node* next;
    Node* random;

    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->random = NULL;
    }
};

Node* copyRandomList(Node* head) {

    // step 1 : create the deep copy without assigning random pointer
    Node* dummy = new Node(0);
    Node* tempD = dummy;
    Node* temp = head;
    while(temp != NULL) {
        Node* a = new Node(temp->val);
        tempD->next = a;
        temp = temp->next;
        tempD = tempD->next;
    }
    Node* duplicate = dummy->next;

    // step 2 : Alternate Connections Creation
    Node* a = head;
    Node* b = duplicate;
    Node* dumm = new Node(-1);
    Node* tD = dumm;

    while(b != NULL) { // a becomes NULL after b
        tD->next = a;
        a = a->next;
        tD = tD->next;

        tD->next = b;
        b = b->next;
        tD = tD->next;
    }
    dumm = dumm->next; // Alternate Combined List

    // step 3 : Assigning Random pointers
    Node* t1 = dumm; // t1 will traverse in the original list 
    Node* t2 = dumm; // t2 will traverse at duplicate list
    while(t1 != NULL) {
        Node* t2 = t1->next; // for duplicate
        if(t1->random != NULL) {
            t2->random = t1->random->next;
        }
        t1 = t1->next->next;
    }

    // step 4 : Seperating the List
    Node* d1 = new Node(-1);
    Node* d2 = new Node(-1);
    t1 = d1;
    t2 = d2;
    Node* t = dumm;
    while(t != NULL) {
        t1->next = t;
        t = t->next;
        t1 = t1->next;

        t2->next = t;
        t = t->next;
        t2 = t2->next;
    }
    t1->next = NULL;
    t2->next = NULL;
    d1 = d1->next; // original list with random pointers
    d2 = d2->next; // duplicate or deep copy with random pointers
    return d2;
}

int main()
{
    return 0;
}