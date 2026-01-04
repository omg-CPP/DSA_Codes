#include <iostream>
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

class DoublyLinkedList { // user defined data structure
public : 
    Node* head;
    Node* tail;
    int size;

    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    // display the LinkedList
    void displayDLL() {
        Node* temp = head;
        while(temp != NULL) {
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    // insert at tail
    void insertAtTail(int val) {
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

    // insert at head
    void insertAtHead(int val) {
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

    // insert at any Index
    void insertAtAnyIndex(int idx, int val) {
        if(idx < 0 || idx > size) {
            cout<<"Invalid Index"<<endl;
        }
        else if(idx == 0) {
            insertAtHead(val);
        }
        else if(idx == size) {
            insertAtTail(val);
        }
        else {
            Node* newNode = new Node(val);
            Node* temp = head;
            for(int i = 1 ; i <= idx-1 ; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            newNode->next->prev = newNode;
            newNode->prev = temp;
        }
        size++;
    }

    // delete at Head
    void deleteAtHead() {
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

    // delete at Tail
    void deleteAtTail() {
        if(size == 0) {
            cout<<"List is Empty"<<endl;
            return;
        }
        else if(size == 1) {
            deleteAtHead();
            return;
        }
        Node* temp = tail->prev;
        temp->next = NULL;
        tail = temp;
        size--;
    }

    // Delete at any index
    void deleteAtAnyIndex(int idx) {
        if(size == 0) {
            cout<<"List is Empty"<<endl;
        }
        else if(idx < 0 || idx >= size) {
            cout<<"Invalid Index"<<endl;
        }
        else if(idx == 0) {
            deleteAtHead();
        }
        else if(idx == size-1) {
            deleteAtTail();
        }
        else {
            Node* temp = head;
            for(int i = 1 ; i <= idx-1 ; i++) {
                temp = temp->next;
            }
            temp->next = temp->next->next;
            temp->next->prev = temp;
            size--;
        }
    }

    // Get Element at any Index
    int getElementAtAnyIndex(int idx) {
        if(idx < 0 || idx >= size) {
            cout<<"Invalid Index"<<endl;
            return -1;
        }
        else if(idx == 0) {
            return head->val;
        }
        else if(idx == size-1) {
            return tail->val;
        }
        else {
            Node* temp = head;
            for(int i = 1 ; i <= idx ; i++) {
                temp = temp->next;
            }
            return temp->val;
        }
    }

    int getElement(int idx) {
        // Optimised
        if(idx < 0 || idx >= size) {
            cout<<"Invalid Index"<<endl;
            return -1;
        }
        else if(idx == 0) {
            return head->val;
        }
        else if(idx == size-1) {
            return tail->val;
        }
        else {
            if(idx < size/2) {
                Node* temp = head;
                for(int i = 1 ; i <= idx ; i++) {
                    temp = temp->next;
                }
                return temp->val;
            }
            else { // idx >= size/2
                Node* temp = tail;
                for(int i = 1 ; i <= size-idx-1 ; i++) {
                    temp = temp->prev;
                }
                return temp->val;
            }
        }
    }
};

int main()
{
    DoublyLinkedList list;

    // Insert At Tail

    list.insertAtTail(10);
    list.displayDLL(); // 10 

    list.insertAtTail(20);
    list.displayDLL(); // 10 20 

    list.insertAtTail(30);
    list.displayDLL(); // 10 20 30 

    list.insertAtTail(40);
    list.displayDLL(); // 10 20 30 40 

    list.insertAtTail(50);
    list.displayDLL(); // 10 20 30 40 50 

    // Insert At Head

    list.insertAtHead(1);
    list.displayDLL(); // 1 10 20 30 40 50 

    list.insertAtHead(2);
    list.displayDLL(); // 2 1 10 20 30 40 50 

    list.insertAtHead(3);
    list.displayDLL(); // 3 2 1 10 20 30 40 50 

    // Insert At Any Index
    
    list.insertAtAnyIndex(3,15);
    list.displayDLL(); // 3 2 1 15 10 20 30 40 50 

    list.insertAtAnyIndex(4,25);
    list.displayDLL(); // 3 2 1 15 25 10 20 30 40 50  

    // Get Element 

    cout<<list.size<<endl; // 10 => size/2 = 5 
    cout<<list.getElement(3)<<endl; // idx < 5 // 15
    cout<<list.getElement(4)<<endl; // idx < 5 // 25
    cout<<list.getElement(5)<<endl; // idx = 5 // 10
    cout<<list.getElement(7)<<endl; // idx > 5 // 30
    cout<<list.getElement(8)<<endl; // idx > 5 // 40

    // Delete At Head

    list.deleteAtHead();
    list.displayDLL(); // 2 1 15 25 10 20 30 40 50

    list.deleteAtHead();
    list.displayDLL(); // 1 15 25 10 20 30 40 50

    list.deleteAtHead();
    list.displayDLL(); // 15 25 10 20 30 40 50

    // Delete At Tail

    list.deleteAtTail();
    list.displayDLL(); // 15 25 10 20 30 40

    list.deleteAtTail();
    list.displayDLL(); // 15 25 10 20 30

    // Delete At Any Index

    list.deleteAtAnyIndex(2);
    list.displayDLL(); // 15 25 20 30

    list.deleteAtAnyIndex(1);
    list.displayDLL(); // 15 20 30

    // Get Element At Any Index

    cout<<list.getElementAtAnyIndex(0)<<endl; // 15
    cout<<list.getElementAtAnyIndex(1)<<endl; // 20
    cout<<list.getElementAtAnyIndex(2)<<endl; // 30

    return 0;
}