#include <iostream>
using namespace std;

class Cricketer {
    public : 
    string name;
    int runs;

    // Cricketer(string Name, int Runs) {
    //     name = Name;
    //     runs = Runs;
    // }

    Cricketer(string name, int runs) {
        this->name = name;
        this->runs = runs;
    }
};

// Deep Copy : Pass By Value

void print(Cricketer c) { 
    cout<<c.name<<" "<<c.runs<<endl;
}

int main()
{
    Cricketer c1("Virat Kohli",27000);
    print(c1);
    // Virat Kohli 27000
    Cricketer c2("Rohit Sharma",19000);
    print(c2);
    // Rohit Sharma 19000
    return 0;
}