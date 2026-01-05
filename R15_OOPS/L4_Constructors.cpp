#include <iostream>
using namespace std;

class Student {
    // Student is a class
    public : // access modifier
    string name;
    int rollno;
    float cgpa;

    Student() { // default Constructor
        // for normal initialisation
    }

    // parameterised Constructor
    Student(string Name, int RollNo, float CGPA) { 
        // Used to assign values
        name = Name;
        rollno = RollNo;
        cgpa = CGPA;
    }
};

int main()
{
    // s1 is a object of the class Student created inside main()
    Student s1("Raghav Garg",82,7.6);
    // Student is a user defined data type
    // s1 is a object of the class Student

    cout<<s1.name<<" "<<s1.rollno<<" "<<s1.cgpa<<endl;
    // Raghav Garg 82 7.6

    // override
    s1.name = "Atul";
    cout<<s1.name<<" "<<s1.rollno<<" "<<s1.cgpa<<endl;
    // Atul 82 7.6

    Student s2;
    // s2 is a object of the class Student
    s2.name = "Om Gupta";
    s2.rollno = 27;
    s2.cgpa = 8.3;

    cout<<s2.name<<" "<<s2.rollno<<" "<<s2.cgpa<<endl;
    // Om Gupta 27 8.3

    Student s3;
    cout<<s3.name<<" "<<s3.rollno<<" "<<s3.cgpa<<endl;
    //  17967528 8.99942e-039 -> Garbage Values
    return 0;
}