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

    cout<<a.next<<endl; // 0
    cout<<b.next<<endl; // 0
    cout<<c.next<<endl; // 0
    cout<<d.next<<endl; // 0

    // Linking 
    a.next = &b;
    b.next = &c;
    c.next = &d;

    // After Linking The Linked List
    cout<<&a<<endl; // 0x61ff08

    cout<<a.next<<endl; // 0x61ff00
    cout<<&b<<endl; // 0x61ff00

    cout<<b.next<<endl; // 0x61fef8
    cout<<&c<<endl; // 0x61fef8

    cout<<c.next<<endl; // 0x61fef0
    cout<<&d<<endl; // 0x61fef0

    cout<<d.next<<endl; // 0

    //-----------------------------------------

    cout<<a.value<<endl;

    cout<<b.value<<endl; // 20
    cout<<(*(a.next)).value<<endl; // 20
    cout<<(a.next)->value<<endl; // 20

    cout<<c.value<<endl; // 30
    cout<<(*(b.next)).value<<endl; // 30
    cout<<(b.next)->value<<endl; // 30

    cout<<d.value<<endl; // 40
    cout<<(*(c.next)).value<<endl; // 40
    cout<<(c.next)->value<<endl; // 40

    //-------------------------------------------

    // Using Pointers
    cout<<a.value<<endl; // 10
    cout<<(a.next)->value<<endl; // 20
    cout<<((a.next)->next)->value<<endl; // 30
    cout<<(((a.next)->next)->next)->value<<endl; // 40

    // Using Dereferencing Operators
    cout<<a.value<<endl; // 10
    cout<<(*(a.next)).value<<endl; // 20
    cout<<(*((*(a.next)).next)).value<<endl; // 30
    cout<<(*((*((*(a.next)).next)).next)).value<<endl; // 40
    return 0;
}