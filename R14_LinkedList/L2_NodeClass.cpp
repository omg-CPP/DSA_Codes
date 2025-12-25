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

int main()
{
    // 10 20 30 40
    Node a(10);
    cout<<a.value<<endl; // 10
    Node b(20);
    cout<<b.value<<endl; // 20
    Node c(30);
    cout<<c.value<<endl; // 30
    Node d(40);
    cout<<d.value<<endl; // 40

    // When not linked as well as not set to null
    cout<<&a<<endl; // 0x61ff08
    cout<<a.next<<endl; // 0x401c1b
    cout<<&b<<endl; // 0x61ff00
    cout<<b.next<<endl; // 0x401bc0
    cout<<&c<<endl; // 0x61fef8
    cout<<c.next<<endl; // 0x61ff08
    cout<<&d<<endl; // 0x61fef0
    cout<<d.next<<endl; // 0x1bd88913

    // After manual nulling all the nodes
    a.next = NULL;
    cout<<a.next<<endl; // 0
    b.next = NULL;
    cout<<b.next<<endl; // 0
    c.next = NULL;
    cout<<c.next<<endl; // 0
    d.next = NULL;
    cout<<d.next<<endl; // 0

    // Linking 
    a.next = &b;
    b.next = &c;
    c.next = &d;
    // d.next = NULL;

    // After Linking The Linked List
    cout<<&a<<endl; // 0x61ff08
    cout<<a.next<<endl; // 0x61ff00
    cout<<&b<<endl; // 0x61ff00
    cout<<b.next<<endl; // 0x61fef8
    cout<<&c<<endl; // 0x61fef8
    cout<<c.next<<endl; // 0x61fef0
    cout<<&d<<endl; // 0x61fef0
    cout<<d.next<<endl; // 0
    return 0;
}