// Leetcode : 622
#include <iostream>
#include <queue>
using namespace std;

class MyCircularQueue {
public :
    int f; // front
    int r; // back / rear
    int s; // current size of queue
    int c; // maximum capacity of the queue
    vector<int> v; // vector
    MyCircularQueue(int k) { // k is capacity of vector
        f = 0;
        r = 0;
        s = 0;
        c = k;
        v.resize(k);
    }

    bool enQueue(int val) { // PUSH BACK
        if(s == c) {
            return false;
        }
        else { // s < c 
            v[r] = val;
            r++;
            if(r == c) {
                r = r%c; // r = 0
            }
            s++;
            return true;
        }
    }

    bool deQueue() { // POP FRONT
        if(s == 0) {
            return false;
        }
        else {
            f++;
            if(f == c) {
                f = f%c; // f = 0
            }
            s--;
            return true;
        }
    }

    int Front() { // front
        if(s == 0) {
            return -1;
        }
        else {
            return v[f];
        }
    }

    int Rear() { // back 
        if(s == 0) {
            return -1;
        }
        else if(r == 0) {
            return v[c-1];
        }
        else {
            return v[r-1];
        }
    }

    bool isEmpty() { // empty
        if(s == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    bool isFull() { // full
        if(s == c) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main()
{
    return 0;
}