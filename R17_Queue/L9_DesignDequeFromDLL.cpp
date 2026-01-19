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

class Node {
public :
    int val;
    Node* prev;
    Node* next;

    Node(int val) {
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

class Deque { // user defined data structure
public : 
    Node* head;
    Node* tail;
    int size;

    Deque() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    // insert at tail : PUSH_BACK
    void pushBack(int val) {
        Node* newNode = new Node(val);
        if(size == 0) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    // insert at head : PUSH_FRONT
    void pushFront(int val) {
        Node* newNode = new Node(val);
        if(size == 0) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }


    // delete at Head : POP_FRONT
    void popFront() {
        if(size == 0) {
            cout<<"List is Empty"<<endl;
            return;
        }
        head = head->next;
        if(head == NULL) {
            tail = NULL;
        }
        if(head != NULL) {
            head->prev = NULL;
        }
        size--;
    }

    // delete at Tail : POP_BACK
    void popBack() {
        if(size == 0) {
            cout<<"List is Empty"<<endl;
            return;
        }
        else if(size == 1) {
            popFront();
            return;
        }
        Node* temp = tail->prev;
        temp->next = NULL;
        tail = temp;
        size--;
    }

    int front() {
        if(size == 0) {
            cout<<"Deque is empty"<<endl;
            return -1;
        }
        else {
            return head->val;
        }
    }

    int back() {
        if(size == 0) {
            cout<<"Deque is empty"<<endl;
            return -1;
        }
        else {
            return tail->val;
        }
    }

    // Display the Deque
    void display() {
        Node* temp = head;
        while(temp != NULL) {
            cout<<temp->val<<" ";
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
    Deque dq;
    cout<<dq.empty()<<endl; // 1
    dq.pushBack(10);
    dq.pushBack(20);
    dq.pushBack(30);
    dq.pushBack(40);
    cout<<dq.front()<<endl; // 10
    cout<<dq.back()<<endl; // 40
    cout<<dq.empty()<<endl; // 0
    dq.display(); // 10 20 30 40 
    dq.popBack();
    dq.display(); // 10 20 30 
    dq.pushFront(15);
    dq.pushFront(25);
    dq.pushFront(35);
    dq.pushFront(45);
    cout<<dq.size<<endl; // 7
    cout<<dq.front()<<endl; // 45
    cout<<dq.back()<<endl; // 30
    cout<<dq.empty()<<endl; // 0
    dq.display(); // 45 35 25 15 10 20 30 
    dq.popFront();
    dq.popFront();
    dq.display(); // 25 15 10 20 30

    cout<<dq.front()<<endl; // 25
    cout<<dq.back()<<endl; // 30
    cout<<dq.empty()<<endl; // 0
    cout<<dq.size<<endl; // 5
    return 0;
}