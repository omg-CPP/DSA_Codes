#include <iostream>
using namespace std;
class Node { // Linked List Node
    public :
    int value;
    Node* next;
    // Constructor
    Node(int value) {
        this->value = value;
        this->next = NULL;
    }
};

// T.C. = O(n)
// S.C. = O(1)
void display(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->value<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int size(Node* head) {
    int n = 0;
    Node* temp = head;
    while(temp != NULL) {
        n++;
        temp = temp->next;
    }
    return n;
}

// T.C. = O(n)
// S.C. = O(n)
void recDisplay(Node* head) {
    if(head == NULL) {
        return;
    }
    cout<<head->value<<" ";
    recDisplay(head->next);
}


void recReverseDisplay(Node* head) {
    if(head == NULL) {
        return;
    }
    recReverseDisplay(head->next);
    cout<<head->value<<" ";
}

void insertAtEnd(Node* head, int value) {
    Node* t = new Node(value);
    while(head->next != NULL) {
        head = head->next;
    }
    head->next = t;
}

int main()
{
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    display(a); // 10 20 30 40 50 
    cout<<size(a)<<endl; // 4
    recDisplay(a); // 10 20 30 40 50 
    cout<<endl;
    recReverseDisplay(a); // 50 40 30 20 10 

    cout<<endl;
    display(a); // 10 20 30 40 50 

    insertAtEnd(a,60);
    display(a); // 10 20 30 40 50 60 
    return 0; 
}