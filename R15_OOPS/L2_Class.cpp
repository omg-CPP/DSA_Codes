#include <iostream>
using namespace std;

class Car {
    public : 
    // attributes of the class
    string name;
    int price;
    int seats;
    string type;

    // default Constructor
    Car() {

    }
    // parameterised Constructor
    Car(string Name, int Price, int Seats, string Type) {
        name = Name;
        price = Price;
        seats = Seats;
        type = Type;
    }
};

int main()
{
    Car c1;
    c1.name = "Honda City";
    c1.price = 1500000;
    c1.seats = 5;
    c1.type = "Sedan";
    cout<<c1.name<<" "<<c1.price<<" "<<c1.seats<<" "<<c1.type<<endl;
    // Honda City 1500000 5 Sedan

    Car c2;
    c2.name = "Maruti Swift";
    c2.price = 700000;
    c2.seats = 5;
    c2.type = "Hatchback";
    cout<<c2.name<<" "<<c2.price<<" "<<c2.seats<<" "<<c2.type<<endl;
    // Maruti Swift 700000 5 Hatchback

    Car c3;
    c3.name = "Toyota Fortuner";
    c3.price = 5200000;
    c3.seats = 8;
    c3.type = "SUV";
    cout<<c3.name<<" "<<c3.price<<" "<<c3.seats<<" "<<c3.type<<endl;
    // Toyota Fortuner 5200000 8 SUV

    // Assigning through Constructor
    Car c4("Hyundai Verna",1200000,5,"Sedan");
    cout<<c4.name<<" "<<c4.price<<" "<<c4.seats<<" "<<c4.type<<endl;
    // Hyundai Verna 1200000 5 Sedan
    return 0;
}