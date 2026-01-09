#include <bits/stdc++.h>
#include <iostream>
#include <stack>
using namespace std;

class Node {
public : 
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class Stack {
public :
    Node* head;
    int size;

    Stack() {
        head = NULL;
        size = 0;
    }

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void pop() {
        if(head == NULL) {
            cout<<"Stack Underflow"<<endl;
        }
        else {
            head = head->next;
            size--;
        }
    }

    int top() {
        if(head == NULL) {
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        else {
            return head->val;
        }
    }

    void displayReverseStack() {
        Node* temp = head;
        while(temp != NULL) {
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    // To reverse a linked list recursively
    void print(Node* temp) {
        if(temp == NULL) {
            return;
        }
        print(temp->next);
        cout<<temp->val<<" ";
    }

    void displayStack() {
        Node* temp = head;
        print(temp);
        cout<<endl;
    }
};

int main()
{
    Stack st;

    cout<<st.top()<<endl; // Stack Underflow
    // -1

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    cout<<st.size<<endl; // 6
    cout<<st.top()<<endl; // 60

    st.displayReverseStack();
    // 60 50 40 30 20 10 

    st.displayStack();
    // 10 20 30 40 50 60 
    return 0;
}