// Leetcode : 641 : Using Array / Vector
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

// Implementation of Deque using Circular Array / vector

class MyCircularDeque {

private :
    int f; // front
    int r; // rear / back
    int s; // current size of deque
    int c; // maximum capacity of deque
    vector<int> v;

public:
    MyCircularDeque(int k) {
        f = 0;
        r = 0;
        s = 0;
        c = k;
        v.resize(k);
    }
    
    bool insertFront(int value) { // push_front
        if(isFull()) {
            return false;
        }
        else {
            f = (f-1+c) % c;
            v[f] = value;
            s++;
            return true;
        }
    }
    
    bool insertLast(int value) { // push_back
        if(isFull()) {
            return false;
        } 
        else {
            v[r] = value;
            r = (r+1) % c;
            s++;
            return true;
        }
    }
    
    bool deleteFront() { // pop_front
        if(isEmpty()) {
            return false;
        }
        else {
            f = (f+1) % c;
            s--;
            return true;
        }
    }
    
    bool deleteLast() { // pop_back
        if(isEmpty()) {
            return false;
        }
        else {
            r = (r-1+c) % c;
            s--;
            return true;
        }
    }
    
    int getFront() {
        if(isEmpty()) {
            return -1;
        }
        else {
            return v[f];
        }
    }
    
    int getRear() {
        if(isEmpty()) {
            return -1;
        }
        else {
            return v[(r-1+c) % c];
        }
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