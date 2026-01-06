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

};


int main()
{
    int x = 6;
    cout<<x<<endl; // 6
    int* ptr = &x;
    cout<<ptr<<endl; // 0x61ff08
    cout<<*ptr<<endl; // 6

    // Dynamic Memory Allocation
    // RunTime me memory allocate hoti hai
    int* p = new int(5245);
    cout<<*p<<endl; // 5245

    // Stored in heap memory
    int* q = new int[10];

    // Compile Time Memory Allocation
    Cricketer c1("Virat Kohli",27000,55.2);

    // Run Time Memory Allocation
    Cricketer* pt = new Cricketer("Rohit Sharma",19000,47.8);

    cout<<c1.name<<" "<<c1.runs<<endl;
    // Virat Kohli 27000

    cout<<(*pt).name<<" "<<(*pt).runs<<endl;
    // Rohit Sharma 19000
    cout<<pt->name<<" "<<pt->runs<<endl;
    // Rohit Sharma 19000
    return 0;
}