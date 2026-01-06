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


// Function Outside the class

// void print(Cricketer c) { 
//     cout<<c.name<<" "<<c.runs<<endl;
// }

int main()
{
    Cricketer c1("Virat Kohli",27000,55.2);
    c1.print();
    // Virat Kohli 27000 55.2
    Cricketer c2("Rohit Sharma",19000,47.8);
    c2.print();
    // Rohit Sharma 19000 47.8

    // // change
    // c1.name = "Sachin Tendulkar";
    // c1.print();
    // // Sachin Tendulkar 27000 55.2
    return 0;
}