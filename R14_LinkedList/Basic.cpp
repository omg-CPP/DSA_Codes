#include <iostream>
using namespace std;

class Node {
public :
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void change(Node* head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
    cout<<head<<endl; // 0
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

    // Node* temp = a;

    // cout<<a<<endl; // 0x11118e0
    // cout<<temp<<endl; // 0x11118e0

    // while(temp != NULL) {
    //     cout<<temp->data<<" ";
    //     temp = temp->next;
    // }
    // cout<<endl;
    // // 10 20 30 40 50 

    // cout<<a<<endl; // 0x11118e0
    // cout<<temp<<endl; // 0

    cout<<a<<endl; // 0x10218e0
    change(a); // 10 20 30 40 50 
    cout<<a<<endl; // 0x10218e0

    Node* temp = a;
    // Deep Copy is generated : changes in temp will not affect a
    return 0;
}