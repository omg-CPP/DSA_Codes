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

void display(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->value<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    // Dynamic Allocation : Run Time
    // There is no name of any linked list
    // a, b, c, d are just node pointers which store the addresses of the linked list and via them we could print and modify the value and next of linked list.

    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);

    a->next = b;
    // (*a).next = b;

    b->next = c;
    // (*b).next = c;

    c->next = d;
    // (*c).next = d;

    Node* temp = a;
    while(temp != NULL) {
        cout<<temp->value<<" ";
        temp = temp->next;
    }
    cout<<endl;
    // 10 20 30 40

    cout<<a->value<<endl; // 10
    cout<<(a->next)->value<<endl; // 20
    cout<<((a->next)->next)->value<<endl; // 30
    cout<<(((a->next)->next)->next)->value<<endl; // 40

    display(a);
    // 10 20 30 40 
    return 0;
}