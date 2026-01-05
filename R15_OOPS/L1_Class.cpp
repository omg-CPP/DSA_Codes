#include <iostream>
using namespace std;

class Student {
    // Student is a class
    public : // access modifier
    string name;
    int rollno;
    float cgpa;
};

int main()
{
    Student s1;
    // Student is a user defined data type
    // s1 is a object of the class Student
    s1.name = "Raghav Garg";
    s1.rollno = 82;
    s1.cgpa = 7.6;

    cout<<s1.name<<" "<<s1.rollno<<" "<<s1.cgpa<<endl;
    // Raghav Garg 82 7.6

    Student s2;
    // s2 is a object of the class Student
    s2.name = "Om Gupta";
    s2.rollno = 27;
    s2.cgpa = 8.3;

    cout<<s2.name<<" "<<s2.rollno<<" "<<s2.cgpa<<endl;
    // Om Gupta 27 8.3

    Student s3;
    // s3 is a object of the class Student
    cout<<"Enter name : ";
    getline(cin,s3.name);
    cout<<"Enter rollno : ";
    cin>>s3.rollno;
    cout<<"Enter cgpa : ";
    cin>>s3.cgpa;

    cout<<s3.name<<" "<<s3.rollno<<" "<<s3.cgpa<<endl;

    // Enter name : Atul Sharma
    // Enter rollno : 45
    // Enter cgpa : 8.9
    // Atul Sharma 45 8.9

    return 0;
}