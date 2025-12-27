// Leetcode - 237
#include <iostream>
using namespace std;

// There is a singly-linked list head and we want to delete a node node in it.

// You are given the node to be deleted node. You will not be given access to the first node of head.

// All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.

// Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:

// The value of the given node should not exist in the linked list.
// The number of nodes in the linked list should decrease by one.
// All the values before node should be in the same order.
// All the values after node should be in the same order.

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

// {10,20,30,40,50}
// node -> 30
// step 1 : 10->20->40->40->50->NULL
// step 2 : 10->20->40->50->NULL
void deleteNode(Node* node) {
    node->value = node->next->value;
    node->next = node->next->next;
}

int main() {
    return 0;
}

