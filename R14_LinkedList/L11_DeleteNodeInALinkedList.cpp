#include <iostream>
using namespace std;

// Leetcode - 237

class Node {
    public : 
    int value;
    Node* next;

    // Default Constructor
    Node(int value) {
        this->value = value;
        this->next = NULL;
    }
};

void display(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->value<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* deleteNode2(Node* head, Node* target) {
    if(head == target) {
        head = head->next;
        return head;
    }
    Node* temp = head;
    while(temp->next != target) {
        temp = temp->next;
    }
    temp->next = temp->next->next;
    return head;
}

Node* deleteNode3(Node* head, int targetValue) {
    if(head->value == targetValue) {
        head = head->next;
        return head;
    }
    Node* temp = head;
    while(temp->next->value != targetValue) {
        temp = temp->next;
    }
    temp->next = temp->next->next;
    return head;
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

    // Node to be deleted is given

    // Node* head = a;
    // display(head); // 10 20 30 40 50 
    // head = deleteNode2(head,d);
    // display(head); // 10 20 30 50 
    // head = deleteNode2(head,a);
    // display(head); // 20 30 50 

    // Value of Node to be deleted is given

    Node* head = a;
    display(head); // 10 20 30 40 50 
    head = deleteNode3(head,40);
    display(head); // 10 20 30 50 
    head = deleteNode3(head,10);
    display(head); // 20 30 50 

    return 0;
}