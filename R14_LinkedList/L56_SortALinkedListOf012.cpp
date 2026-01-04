#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <climits>
#include <cmath>
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

// Helper function to create a linked list from an array
Node* createLinkedList(int arr[], int n) {
    if(n == 0) {
        return NULL;
    }
    Node* head = new Node(arr[0]);
    Node* curr = head;
    for (int i = 1 ; i < n ; i++) {
        Node* newNode = new Node(arr[i]);
        curr->next = newNode;
        curr = curr->next;
    }
    return head;
}

void printLinkedList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


Node* sortLinkedListOf0_1_2(Node* head) {
    // Dummy nodes for the three lists
    Node* dummy0 = new Node(-1);
    Node* dummy1 = new Node(-1);
    Node* dummy2 = new Node(-1);
    // Current pointers for the three lists
    Node* zero = dummy0;
    Node* one = dummy1;
    Node* two = dummy2;

    // Traverse the original list and segregate nodes
    Node* curr = head;
    while(curr != NULL) {
        if(head == NULL || head->next == NULL) {
            return head; 
        }
        if(curr->data == 0) {
            zero->next = curr;
            zero = zero->next;
            curr = curr->next;
        }
        else if(curr->data == 1) {
            one->next = curr;
            one = one->next;
            curr = curr->next;
        }
        else { // curr->data == 2
            two->next = curr;
            two = two->next;
            curr = curr->next;
        }
    }
    // Connect the three lists
    if(dummy1->next != NULL) {
        zero->next = dummy1->next;
        one->next = dummy2->next;
        two->next = NULL;
    }
    else { // dummy1->next == NULL
        zero->next = dummy2->next;
        two->next = NULL;
    }
    Node* newHead = dummy0->next;
    return newHead;
}

int main()
{
    // head = 1 → 2 → 2 → 1 → 2 → 0 → 2 → 2
    int arr[] = {1,2,2,1,2,0,2,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* head = createLinkedList(arr,n);
    
    cout<<"Original LinkedList : ";
    printLinkedList(head);
    // Original LinkedList : 1 2 2 1 2 0 2 2 
    
    Node* sortedHead = sortLinkedListOf0_1_2(head);
    
    cout<<"Sorted LinkedList : ";
    printLinkedList(sortedHead);
    // Sorted LinkedList : 0 1 1 2 2 2 2 2 
    return 0;
}