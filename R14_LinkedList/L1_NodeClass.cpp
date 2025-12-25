#include <iostream>
using namespace std;

class Node {
    public :
    int value;
    Node* next;
};

int main()
{
    // 10 20 30 40
    Node a;
    a.value = 10;
    Node b;
    b.value = 20;
    Node c;
    c.value = 30;
    Node d;
    d.value = 40;
    // Linking 
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = NULL;
    return 0;
}