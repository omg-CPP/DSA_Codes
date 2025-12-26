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

// Predict the output for linked list = 1->2->3->4->5->NULL
void traverse(Node* head) {
    while(head != NULL && (head->next) != NULL) {
        cout<<head->value<<" ";
        head = (head->next)->next;
    }
    cout<<endl;
}

int main()
{
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);
    // Linking the Linked List
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    traverse(a); // 10 30
    return 0;
}