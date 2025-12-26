#include <iostream>
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

class LinkedList { // user defined data structure

    public :
    Node* head;  // head pointer
    Node* tail;  // tail pointer
    int size;

    // Constructor
    LinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    // Display the LinkedList
    void display() {
        Node* temp = head;
        while(temp != NULL) {
            cout<<temp->value<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    // Insert At End Function : Insert at Tail
    // T.C. = O(1)
    void insertAtEnd(int value) {
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

    // Insert At Beginning Function : Insert at Head
    // T.C. = O(1)
    void insertAtBeginning(int value) {
        Node* temp = new Node(value);
        if(size == 0) {
            head = tail = temp;
        }
        else { // size > 0
            temp->next = head;
            head = temp;
        }
        size++;
    }

    // Insert At Any Index Function : Insert at Middle of LinkedList
    void insertAtAnyIndex(int idx, int value) {
        if(idx < 0 || idx > size) {
            cout<<"Invalid Index"<<endl;
        }
        else if(idx == 0) { // Insert at Head or Beginning
            insertAtBeginning(value);
        }
        else if(idx == size) { // Insert at Tail or End
            insertAtEnd(value);
        }
        else { // Insert At Middle of LinkedList
            Node* temp = head;
            Node* t = new Node(value);
            for(int i = 1 ; i <= idx-1 ; i++) {
                temp = temp->next;
            }
            t->next = temp->next;
            temp->next = t;
            size++;
        }
    }

    // get Element at any index Function
    int getElementAtAnyIndex(int idx) {
        if(idx < 0 || idx >= size) {
            cout<<"Invalid Index"<<endl;
            return -1;
        }
        else if(idx == 0) { 
            return head->value;
        }
        else if(idx == size-1) {
            return tail->value;
        }
        else {
            Node* temp = head;
            for(int i = 1 ; i <= idx ; i++) {
                temp = temp->next;
            }
            return temp->value;
        }
    }

    void deleteAtHead() {
        if(size == 0) { // LinkedList is empty
            cout<<"LinkedList is empty"<<endl;
        }
        else if(size == 1) {
            head = tail = NULL;
            size--;
        }
        else if(size > 1) {
            head = head->next;
            size--;
        }
    }

    void deleteAtTail() {
        if(size == 0) {
            cout<<"LinkedList is empty"<<endl;
        }
        else if(size == 1) {
            head = tail = NULL;
            size--;
        }
        else if(size > 1) {
            Node* temp = head;
            for(int i = 1 ; i <= size-2 ; i++) {
                temp = temp->next;
            }
            temp->next = NULL;
            tail = temp;
            size--;
        }
    }

    void deleteAtAnyIndex(int idx) {
        if(idx < 0 || idx >= size) {
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
            size--;
        }
    }
};

int main()
{
    LinkedList ll; // {}
    cout<<ll.size<<endl; // 0

    // -------------------- Insert At Tail ------------------------------

    ll.insertAtEnd(10); // {10 -> NULL}
    ll.display(); // 10
    cout<<ll.size<<endl; // 1

    ll.insertAtEnd(20); // {10->20->NULL}
    ll.display(); // 10 20 
    cout<<ll.size<<endl; // 2

    ll.insertAtEnd(30); // {10->20->30->NULL}
    ll.display(); // 10 20 30 
    cout<<ll.size<<endl; // 3

    ll.insertAtEnd(40); // {10->20->30->40->NULL}
    ll.display(); // 10 20 30 40 
    cout<<ll.size<<endl; // 4

    // -------------------- Insert At Head ------------------------------

    ll.insertAtBeginning(1); // {1->10->20->30->40->NULL}
    ll.display(); // 1 10 20 30 40
    cout<<ll.size<<endl; // 5

    ll.insertAtBeginning(2); // {2->1->10->20->30->40->NULL}
    ll.display(); // 2 1 10 20 30 40
    cout<<ll.size<<endl; // 6


    // -------------------- Insert At Any Index------------------------------

    ll.insertAtAnyIndex(4,80);
    ll.display(); // 2 1 10 20 80 30 40 
    cout<<ll.size<<endl; // 7

    ll.insertAtAnyIndex(6,90);
    ll.display(); // 2 1 10 20 80 30 90 40 
    cout<<ll.size<<endl; // 8

    ll.insertAtAnyIndex(9,100); // Invalid Index
    ll.display(); // 2 1 10 20 80 30 90 40 
    cout<<ll.size<<endl; // 8


    // -------------------- Get Element At Any Index------------------------------

    cout<<ll.getElementAtAnyIndex(-1)<<endl; // Invalid Index : -1
    cout<<ll.getElementAtAnyIndex(0)<<endl; // 2
    cout<<ll.getElementAtAnyIndex(1)<<endl; // 1
    cout<<ll.getElementAtAnyIndex(2)<<endl; // 10
    cout<<ll.getElementAtAnyIndex(3)<<endl; // 20
    cout<<ll.getElementAtAnyIndex(4)<<endl; // 80
    cout<<ll.getElementAtAnyIndex(5)<<endl; // 30
    cout<<ll.getElementAtAnyIndex(6)<<endl; // 90
    cout<<ll.getElementAtAnyIndex(7)<<endl; // 40
    cout<<ll.getElementAtAnyIndex(8)<<endl; // Invalid Index : -1 
    cout<<ll.getElementAtAnyIndex(9)<<endl; // Invalid Index : -1 

    // -------------------- Delete at Head ------------------------------

    ll.deleteAtHead();
    ll.display(); // 1 10 20 80 30 90 40
    cout<<ll.size<<endl; // 7

    // -------------------- Delete at Tail ------------------------------

    ll.deleteAtTail();
    ll.display(); // 1 10 20 80 30 90
    cout<<ll.size<<endl; // 6

    // -------------------- Delete at Any Index------------------------------

    ll.deleteAtAnyIndex(0);
    ll.display(); // 10 20 80 30 90
    cout<<ll.size<<endl; // 5

    ll.deleteAtAnyIndex(5); // // Invalid Index
    ll.display(); // 10 20 80 30 90
    cout<<ll.size<<endl; // 5

    ll.deleteAtAnyIndex(4);
    ll.display(); // 10 20 80 30
    cout<<ll.size<<endl; // 4

    ll.deleteAtAnyIndex(2);
    ll.display(); // 10 20 30
    cout<<ll.size<<endl; // 3

    return 0;
}