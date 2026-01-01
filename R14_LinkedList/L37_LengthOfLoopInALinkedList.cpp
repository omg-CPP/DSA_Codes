#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;   
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Function to return the length
// of loop when slow and fast are
// on the same node
int findLength(Node* slow, Node* fast) {
    // To move first step i.e. to make slow != fast
    int cnt = 1;
    fast = fast->next;

    while(slow != fast){
        cnt++;
        fast = fast->next;
    }
    return cnt;
}

// Function to find the length
// of the loop in a linked list
int lengthOfLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;
    // Step 1: Traverse the list to detect a loop
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;     
        fast = fast->next->next;
        // Step 2: If the slow and fast pointers
        // meet, there is a loop
        if(slow == fast) {
            return findLength(slow, fast);
        }
    }
    // Step 3: If the fast pointer
    // reaches the end, there is no loop
    return 0; 
}

int main() 
{
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    // Create a loop from
    // fifth to second
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    
    // This creates a loop
    fifth->next = second; 

    int loopLength = lengthOfLoop(head);
    if(loopLength > 0) {
        cout<<"Length of the loop : "<<loopLength<<endl;
    } 
    else { // loopLength == 0
        cout<<"No loop found in the linked list"<<endl;
    }
    return 0;
}

// Length of the loop : 4