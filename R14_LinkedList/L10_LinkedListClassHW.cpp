#include <iostream>
using namespace std;

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

class LinkedList {
    public :
    Node* head;
    int size;

    // Default Constructor
    LinkedList() {
        head = NULL;
        size = 0;
    }

    // To Dsiplay the LinkedList

    void display() {
        Node* temp = head;
        while(temp != NULL) {
            cout<<temp->value<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    // To Insert a Node at the End or Tail

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if(size == 0) { // head == NULL
            head = newNode;
        }
        else { // size > 0
            Node* temp = head; // Used for traversing
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    // To Insert a Node at the Beginning or Head

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if(size == 0) { // head == NULL
            head = newNode;
        }
        else { // size > 0
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    // To Insert a Node at any Index 

    void insertAtAnyIndex(int idx, int value) {
        if(idx < 0 || idx > size) {
            cout<<"Invalid Index"<<endl;
        }
        else if(idx == 0) {
            insertAtBeginning(value);
        }
        else if(idx == size) {
            insertAtEnd(value);
        }
        else {
            Node* newNode = new Node(value);
            Node* temp = head;
            for(int i = 1 ; i <= idx-1 ; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            size++;
        }
    }

    // To Delete a Node at the End or Tail

    void deleteAtEnd() {
        if(size == 0) {
            cout<<"LinkedList is empty"<<endl;
        }
        else { // size > 0
            Node* temp = head;
            while(temp->next->next != NULL) {
                temp = temp->next;
            }
            temp->next = NULL;
            size--;
        }
    }

    // To Delete a Node at the Beginning or Head

    void deleteAtBeginning() {
        if(size == 0) {
            cout<<"LinkedList is empty"<<endl;
        }
        else { // size > 0
            head = head->next;
            size--;
        }
    }

    // To Delete a Node at any Index

    void deleteAtAnyIndex(int idx) {
        if(size == 0) {
            cout<<"LinkedList is empty"<<endl;
        }
        else if(idx < 0 || idx >= size) {
            cout<<"Invalid Index"<<endl;
        }
        else if(idx == 0) {
            deleteAtBeginning();
        }
        else if(idx == size-1) {
            deleteAtEnd();
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

    // To Retrieve any element of the LinkedList

    int getElement(int idx) {
        if(idx < 0 || idx >= size) {
            cout<<"Invalid Index"<<endl;
            return -1;
        }
        else if(idx == 0) {
            return head->value;
        }
        else {
            Node* temp = head;
            for(int i = 1 ; i <= idx ; i++) {
                temp = temp->next;
            }
            return temp->value;
        }
    }
};

int main()
{
    LinkedList list;

    cout<<list.size<<endl; // 0

    // To Dsiplay the LinkedList
    // list.display();

    //----------------------------------------------------------

    // Insert a Node at the End or Tail

    list.insertAtEnd(10);
    list.display(); // 10->NULL
    cout<<list.size<<endl; // 1

    list.insertAtEnd(20);
    list.display(); // 10->20->NULL
    cout<<list.size<<endl; // 2

    list.insertAtEnd(30); 
    list.display(); // 10->20->30->NULL
    cout<<list.size<<endl; // 3

    list.insertAtEnd(40);
    list.display(); // 10->20->30->40->NULL 
    cout<<list.size<<endl; // 4

    list.insertAtEnd(50);
    list.display(); // 10->20->30->40->50->NULL 
    cout<<list.size<<endl; // 5

    //----------------------------------------------------

    // Insert a Node at the Beginning or Head

    list.insertAtBeginning(15);
    list.display(); // 15->10->20->30->40->50->NULL 
    cout<<list.size<<endl; // 6

    list.insertAtBeginning(25);
    list.display(); // 25->15->10->20->30->40->50->NULL 
    cout<<list.size<<endl; // 7

    list.insertAtBeginning(35);
    list.display(); // 35->25->15->10->20->30->40->50->NULL 
    cout<<list.size<<endl; // 8

    list.insertAtBeginning(45);
    list.display(); // 45->35->25->15->10->20->30->40->50->NULL 
    cout<<list.size<<endl; // 9

    //-------------------------------------------------------

    // Insert a Node at any Index 

    list.insertAtAnyIndex(2,1);
    list.display(); // 45->35->1->25->15->10->20->30->40->50->NULL 
    cout<<list.size<<endl; // 10

    list.insertAtAnyIndex(5,6);
    list.display(); 
    // 45->35->1->25->15->6->10->20->30->40->50->NULL 
    cout<<list.size<<endl; // 11

    list.insertAtAnyIndex(7,8);
    list.display(); 
    // 45->35->1->25->15->6->10->8->20->30->40->50->NULL 
    cout<<list.size<<endl; // 12

    //----------------------------------------------------------

    // Delete a Node at the End or Tail

    list.deleteAtEnd();
    list.display();
    // 45->35->1->25->15->6->10->8->20->30->40->NULL
    cout<<list.size<<endl; // 11

    list.deleteAtEnd();
    list.display();
    // 45->35->1->25->15->6->10->8->20->30->NULL
    cout<<list.size<<endl; // 10

    list.deleteAtEnd();
    list.display();
    // 45->35->1->25->15->6->10->8->20->NULL
    cout<<list.size<<endl; // 9

    list.deleteAtEnd();
    list.display();
    // 45->35->1->25->15->6->10->8->NULL
    cout<<list.size<<endl; // 8

    //----------------------------------------------------------

    // Delete a Node at the Beginning or Head

    list.deleteAtBeginning();
    list.display(); // 35->1->25->15->6->10->8->NULL
    cout<<list.size<<endl; // 7

    list.deleteAtBeginning();
    list.display(); // 1->25->15->6->10->8->NULL
    cout<<list.size<<endl; // 6

    list.deleteAtBeginning();
    list.display(); // 25->15->6->10->8->NULL
    cout<<list.size<<endl; // 5

    //----------------------------------------------------------
    
    // Delete a Node at any Index

    list.deleteAtAnyIndex(2);
    list.display(); // 25->15->10->8->NULL
    cout<<list.size<<endl; // 4

    list.deleteAtAnyIndex(4); // Invalid Index
    list.display(); // 25->15->10->8->NULL
    cout<<list.size<<endl; // 4

    list.deleteAtAnyIndex(1); 
    list.display(); // 25->10->8->NULL
    cout<<list.size<<endl; // 3

    //-----------------------------------------------------------

    // Retrieve any element of the LinkedList

    cout<<list.getElement(0)<<endl; // 25
    cout<<list.getElement(1)<<endl; // 10
    cout<<list.getElement(2)<<endl; // 8
    cout<<list.getElement(3)<<endl; // InvalidIndex : -1

    return 0;
}