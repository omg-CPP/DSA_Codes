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

    // Linking 
    a.next = &b;
    b.next = &c;
    c.next = &d;

    Node temp = a; // Deep Copy : Pass by value
    while(1) {
        cout<<temp.value<<" ";
        if(temp.next == NULL) {
            break;
        }
        temp = (*(temp.next));
    }
    // 10 20 30 40 
    return 0;
}