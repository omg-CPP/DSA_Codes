#include <iostream>
using namespace std;

class Student {
    // Student is a class
    public : // access modifier
    string name;
    int rollno;
    float cgpa;

    // default Constructor
    Student() {
        // for normal initialisation
    }

    // parameterised Constructor 1
    Student(string Name) {
        name = Name;
    }

    // parameterised Constructor 2
    Student(string Name, int RollNo) {
        name = Name;
        rollno = RollNo;
    }

    // parameterised Constructor 3
    Student(string Name, int RollNo, float CGPA) { 
        // Used to assign values
        name = Name;
        rollno = RollNo;
        cgpa = CGPA;
    }

    // parameterised Constructor 4
    Student(int RollNo, float CGPA, string Name) { 
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

    Student s4("Ajay",49);
    s4.cgpa = 9.0;
    cout<<s4.name<<" "<<s4.rollno<<" "<<s4.cgpa<<endl; 
    // Ajay 49 9

    Student s5("Salman");
    s5.rollno = 87;
    s5.cgpa = 8.6;
    cout<<s5.name<<" "<<s5.rollno<<" "<<s5.cgpa<<endl; 
    // Salman 87 8.6

    Student s6(54,9.8,"Karan");
    cout<<s6.name<<" "<<s6.rollno<<" "<<s6.cgpa<<endl; 
    // Karan 54 9.8

    //------------------------ Copy  Constructor ---------------

    Student s7 = s1; // Deep Copy is created : Pass By Value
    cout<<s7.name<<" "<<s7.rollno<<" "<<s7.cgpa<<endl; 
    // Atul 82 7.6
    s7.name = "Arjun";
    cout<<s1.name<<" "<<s1.rollno<<" "<<s1.cgpa<<endl; 
    // Atul 82 7.6
    cout<<s7.name<<" "<<s7.rollno<<" "<<s7.cgpa<<endl; 
    // Arjun 82 7.6

    Student s8(s1); // Copy Constructor : Deep Copy
    cout<<s1.name<<" "<<s1.rollno<<" "<<s1.cgpa<<endl; 
    // Atul 82 7.6
    cout<<s8.name<<" "<<s8.rollno<<" "<<s8.cgpa<<endl; 
    // Atul 82 7.6

    s8.name = "Sahil";
    cout<<s1.name<<" "<<s1.rollno<<" "<<s1.cgpa<<endl; 
    // Atul 82 7.6
    cout<<s8.name<<" "<<s8.rollno<<" "<<s8.cgpa<<endl; 
    // Sahil 82 7.6
    return 0;
}