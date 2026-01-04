// Doubly LinkedList Manual Representation

#include <iostream>
using namespace std;

class Node {
public :
    int val;
    Node* prev;
    Node* next;

    Node(int val) {
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

void display(Node* head) { // S.C. = O(1)
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// display LL using recursion
void displayRec(Node* head) { // S.C. = O(n)
    if(head == NULL) {
        return;
    }
    cout<<head->val<<" "; // work
    displayRec(head->next); // call
}

// display LL in reverse order using recursion
void displayRecReverse(Node* head) { // S.C. = O(n)
    if(head == NULL) {
        return;
    }
    displayRecReverse(head->next); // call
    cout<<head->val<<" "; // work
}

void displayReverse(Node* tail) { // S.C. = O(1)
    while(tail != NULL) {
        cout<<tail->val<<" ";
        tail = tail->prev;
    }
    cout<<endl;
}

void displayLLWithAnyNodeGiven(Node* node) {
    // first find the head of the LL
    Node* temp = node;
    while(temp->prev != NULL) {
        temp = temp->prev;
    }
    Node* head = temp;
    while(head != NULL) {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

void displayLLWithAnyNodeGivenInReverse(Node* node) {
    // first find the tail of the LL
    Node* temp = node;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    Node* tail = temp;
    while(tail != NULL) {
        cout<<tail->val<<" ";
        tail = tail->prev;
    }
    cout<<endl;
}

int main()
{
    // Doubly LinkedList
    // NULL<-10⇌20⇌30⇌40⇌50->NULL

    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);

    // forward connections
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    // backward connections
    e->prev = d;
    d->prev = c;
    c->prev = b;
    b->prev = a;

    display(a); // 10 20 30 40 50 
    cout<<a<<endl; // 0xfa1990

    displayRec(a); // 10 20 30 40 50 
    cout<<endl;
    cout<<a<<endl; // 0xfa1990

    displayRecReverse(a); // 50 40 30 20 10 
    cout<<endl;
    cout<<a<<endl; // 0xfa1990

    displayReverse(e); // 50 40 30 20 10 

    displayLLWithAnyNodeGiven(c); // 10 20 30 40 50 

    displayLLWithAnyNodeGivenInReverse(c); // 50 40 30 20 10 
    return 0;
}