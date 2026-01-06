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

void change(Cricketer c) {
    c.avg = 77.2;
}

void changeRef(Cricketer* c) {
    // (*c).avg = 77.2; 
    c->avg = 77.2;
}

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

    cout<<p1->name<<endl; // Virat Kohli
    cout<<p1->runs<<endl; // 27000
    cout<<p1->avg<<endl; // 55.2

    c1.print();
    // Virat Kohli 27000 55.2
    change(c1); // Pass by value
    c1.print();
    // Virat Kohli 27000 55.2

    changeRef(p1); // Pass by reference
    c1.print();
    // Virat Kohli 27000 77.2 

    cout<<p1->name<<endl; // Virat Kohli
    cout<<p1->runs<<endl; // 27000
    cout<<p1->avg<<endl; // 77.2

    return 0;
}