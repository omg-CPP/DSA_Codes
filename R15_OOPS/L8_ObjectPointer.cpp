#include <iostream>
using namespace std;

class Cricketer {
    public : 
    string name;
    int runs;
    float avg;

    Cricketer(string name, int runs, float avg) {
        this->name = name;
        this->runs = runs;
        this->avg = avg;
    }

    // Function Inside the class
    void print() {
        cout<<(this->name)<<" "<<(this->runs)<<" "<<(this->avg)<<endl;
    }
};


int main()
{
    Cricketer c1("Virat Kohli",27000,55.2);
    c1.print();
    // Virat Kohli 27000 55.2
    Cricketer c2("Rohit Sharma",19000,47.8);
    c2.print();
    // Rohit Sharma 19000 47.8

    // Object pointer
    Cricketer* p1 = &c1;
    cout<<(*p1).name<<endl; // Virat Kohli
    cout<<(*p1).runs<<endl; // 27000
    cout<<(*p1).avg<<endl; // 55.2

    (*p1).avg = 74.8;
    c1.print();
    // Virat Kohli 27000 74.8

    Cricketer* p2 = &c2;
    cout<<(*p2).name<<endl; // Rohit Sharma
    cout<<(*p2).runs<<endl; // 19000
    cout<<(*p2).avg<<endl; // 47.8

    (*p2).runs = 24000;
    c2.print();
    // Rohit Sharma 24000 47.8

    int x = 4;
    cout<<x<<endl; // 4
    cout<<&x<<endl; // 0x61fe90
    int* p = &x;
    cout<<p<<endl; // 0x61fe90
    cout<<*p<<endl; // 4
    *p = 100;
    cout<<x<<endl; // 100
    return 0;
}