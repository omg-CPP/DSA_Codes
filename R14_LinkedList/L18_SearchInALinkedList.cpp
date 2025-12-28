#include <iostream>
using namespace std;

class Node {
    public :
    int value;
    Node* next;

    Node(int value) {
        this->value = value;
        this->next = NULL;
    }
};

int searchInALinkedList(Node* head, int target) {
    Node* temp = head;
    while(temp != NULL) {
        if(temp->value == target) {
            return true;
        }
        temp = temp->next;
    }
    return false;
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

    cout<<searchInALinkedList(a,10)<<endl; // 1
    cout<<searchInALinkedList(a,20)<<endl; // 1
    cout<<searchInALinkedList(a,30)<<endl; // 1
    cout<<searchInALinkedList(a,40)<<endl; // 1
    cout<<searchInALinkedList(a,50)<<endl; // 1

    cout<<searchInALinkedList(a,100)<<endl; // 0
    return 0;
}