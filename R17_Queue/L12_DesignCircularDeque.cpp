// Leetcode : 641
// Implementation of Deque using Doubly Linked List (DLL)

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include<deque>
using namespace std;

class Node {
public :
    int value;
    Node* prev;
    Node* next;
    Node(int value) {
        this->value = value;
        this->prev = NULL;
        this->next = NULL;
    }
};

class MyCircularDeque {
public:
    int val;
    Node* head;
    Node* tail;
    int s; // current size of deque
    int c; // maximum capacity of deque
    MyCircularDeque(int k) {
        s = 0;
        c = k;
        head = NULL;
        tail = NULL;
    }
    
    bool insertFront(int value) { // pushFront : Insert at Head
        Node* newNode = new Node(value);
        if(isFull()) {
            return false;
        }
        else {
            if(s == 0) {
                head = newNode;
                tail = newNode;
            }
            else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            s++;
            return true;
        }
    }
    
    bool insertLast(int value) { // pushBack
        if(isFull()) {
            return false;
        }
        else {
            Node* newNode = new Node(value);
            if(s == 0) {
                head = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            s++;
            return true;
        }
    }
    
    bool deleteFront() { // popFront
        if(isEmpty()) {
            return false;
        }
        else {
            Node* temp = head;
            head = head->next;
            delete(temp);
            if(head == NULL) {
                tail = NULL;
            }
            if(head != NULL) {
                head->prev = NULL;
            }
            s--;
            return true;
        }
    }
    
    bool deleteLast() { // popBack
        if(isEmpty()) {
            return false;
        }
        else {
            if(s == 1) {
                deleteFront();
            }
            else {
                Node* temp = tail;
                Node* newTail = tail->prev;
                newTail->next = NULL;
                tail = newTail;
                delete(temp);
                s--;
            }
            return true;
        }
    }
    
    int getFront() {
        return isEmpty() ? -1 : head->value;
    }
    
    int getRear() {
        return isEmpty() ? -1 : tail->value;
    }
    
    bool isEmpty() {
        return s == 0 ? true : false;
    }
    
    bool isFull() {
        return s == c ? true : false;
    }
};

int main()
{
    return 0;
}