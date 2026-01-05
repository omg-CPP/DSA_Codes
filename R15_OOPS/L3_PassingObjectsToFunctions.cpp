#include <iostream>
using namespace std;

class Car {
    public : 
    // attributes of the class
    string name;
    int price;
    int seats;
    string type;
};

// Passing Objects to Functions
void print(Car c) { 
    cout<<c.name<<" "<<c.price<<" "<<c.seats<<" "<<c.type<<endl;
}

void changeVarByValue(int a) {
    a = 10;
}

void changeVarByReference(int* p) {
    *p = 10;
}

void changeObjByValue(Car c) { // Deep Copy
    c.name = "Audi A8";
}

void changeObjByReference(Car& c) { // Shallow Copy
    c.name = "Audi A8";
}

int main()
{
    // By Value
    int a = 4;
    cout<<a<<endl; // 4
    changeVarByValue(a);
    cout<<a<<endl; // 4

    // By Reference
    int x = 4;
    cout<<x<<endl; // 4
    changeVarByReference(&x);
    cout<<x<<endl; // 10

    Car c1;
    c1.name = "Honda City";
    c1.price = 1500000;
    c1.seats = 5;
    c1.type = "Sedan";

    print(c1);
    // Honda City 1500000 5 Sedan

    changeObjByValue(c1); // Pass By Value Hua Hai

    print(c1);
    // // Honda City 1500000 5 Sedan

    changeObjByReference(c1); // Pass By Reference Hua Hai

    print(c1);
    // Audi A8 1500000 5 Sedan


    Car c2;
    c2.name = "Maruti Swift";
    c2.price = 700000;
    c2.seats = 5;
    c2.type = "Hatchback";

    print(c2);
    // Maruti Swift 700000 5 Hatchback

    Car c3;
    c3.name = "Toyota Fortuner";
    c3.price = 5200000;
    c3.seats = 8;
    c3.type = "SUV";

    print(c3);
    // Toyota Fortuner 5200000 8 SUV


    return 0;
}