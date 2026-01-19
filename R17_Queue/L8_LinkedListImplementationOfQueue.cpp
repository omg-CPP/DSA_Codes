#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;

class Node { // User defined data type

    public : 
    int value;
    Node* next;
    // Constructor
    Node(int value) {
        this->value = value;
        this->next = NULL;
    }
};

class Queue { // user defined data structure

    public :
    Node* head;  // head pointer
    Node* tail;  // tail pointer
    int size;

    // Constructor
    Queue() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    // PUSH : Insert at Tail
    // T.C. = O(1)
    void push(int value) {
        Node* temp = new Node(value);
        if(size == 0) {
            head = tail = temp;
        }
        else { // size > 0
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    // POP : Delete at Head
    // T.C. = O(1)
    void pop() {
        if(size == 0) { // LinkedList is empty
            cout<<"Queue is empty"<<endl;
        }
        else if(size == 1) {
            head = tail = NULL;
            size--;
        }
        else if(size > 1) {
            Node* temp = head;
            head = head->next;
            size--;
            delete(temp); // No Wastage of memory
        }
    }

    int front() {
        if(size == 0) {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else {
            return head->value;
        }
    }

    int back() {
        if(size == 0) {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else {
            return tail->value;
        }
    }

    // Display the Queue
    void display() {
        Node* temp = head;
        while(temp != NULL) {
            cout<<temp->value<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    bool empty() {
        if(tail == NULL) { // size == 0
            return true;
        }
        else {
            return false;
        }
    }
};


int main()
{
    Queue q;
    cout<<q.empty()<<endl; // 1
    q.pop(); // Queue is Empty
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout<<q.empty()<<endl; // 0
    q.display(); // 10 20 30 40 
    cout<<q.front()<<endl; // 10
    cout<<q.back()<<endl; // 40
    cout<<q.size<<endl; // 4
    q.push(50);
    q.push(60); 
    cout<<q.size<<endl; // 6
    q.display(); // 10 20 30 40 50 60
    q.pop();
    cout<<q.front()<<endl; // 20
    cout<<q.back()<<endl; // 60
    cout<<q.size<<endl; // 5
    q.display(); // 20 30 40 50 60
    return 0;
}