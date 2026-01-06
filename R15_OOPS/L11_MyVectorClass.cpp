#include <iostream>
using namespace std;
class Vector {
public : 
    // data members of the class

    int size;
    int capacity;
    int* arr;

    // Default Constructor

    Vector() {
        size = 0;
        capacity = 1;
        arr = new int[1];
    }

    // member functions of the class

    // To add a element
    void push_back(int val) {
        if(size == capacity) {
            capacity = capacity*2;
            int* newArray = new int[capacity];
            for(int i = 0 ; i < size ; i++) {
                newArray[i] = arr[i];
            }
            arr = newArray;
            arr[size] = val;
            size++;
        }
        else {
            arr[size] = val;
            size++;
        }
    }

    // To delete a element 
    void pop_back() {
        size--;
    }

    // To get element at any index
    int getElement(int idx) {
        if(size == 0) {
            cout<<"Invalid Index";
            return -1;
        }
        if(idx < 0 || idx >= size) {
            cout<<"Invalid Index"<<" ";
            return -1;
        }
        else {
            return arr[idx];
        }
    }

    // To print the Vector
    void displayVector() {
        for(int i = 0 ; i < size ; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    Vector v;
    cout<<v.size<<" "<<v.capacity<<endl; // 0 1

    v.push_back(10);
    cout<<v.size<<" "<<v.capacity<<endl; // 1 1
    v.displayVector(); // 10

    v.push_back(20);
    cout<<v.size<<" "<<v.capacity<<endl; // 2 2 
    v.displayVector(); // 10 20

    v.push_back(30);
    cout<<v.size<<" "<<v.capacity<<endl; // 3 4
    v.displayVector(); // 10 20 30

    v.push_back(40);
    cout<<v.size<<" "<<v.capacity<<endl; // 4 4
    v.displayVector(); // 10 20 30 40

    v.push_back(50);
    cout<<v.size<<" "<<v.capacity<<endl; // 5 8
    v.displayVector(); // 10 20 30 40 50

    v.pop_back();
    cout<<v.size<<" "<<v.capacity<<endl; // 4 8
    v.displayVector(); // 10 20 30 40 

    v.pop_back();
    cout<<v.size<<" "<<v.capacity<<endl; // 3 8
    v.displayVector(); // 10 20 30 

    cout<<v.getElement(-1)<<endl; // Invalid Index -1
    cout<<v.getElement(0)<<endl;  // 10
    cout<<v.getElement(1)<<endl;  // 20
    cout<<v.getElement(2)<<endl;  // 30
    cout<<v.getElement(3)<<endl;  // Invalid Index -1
    return 0;
}