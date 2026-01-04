// Leetcode : 430

#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

Node* flatten(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        Node* a = temp->next;
        if(temp->child != NULL) {
            Node* c = temp->child;
            temp->child = NULL;
            c = flatten(c);
            temp->next = c;
            c->prev = temp;
            while(c->next != NULL) {
                c = c->next;
            }
            c->next = a;
            if(a != NULL) {
                a->prev = c;
            }
        }
        temp = a;
    }
    return head;
}

int main()
{
    return 0;
}