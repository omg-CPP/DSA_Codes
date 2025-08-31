#include <iostream>
#include <math.h>
using namespace std;

// Exceptional Handling

// NAN -> double number

double division(double a, double b) {
    try {
        if (b == 0) {
            throw b;
        }
        else {
            return a/b;
        }
    }
    catch (double r) {
        cout<<"Exception caught : Number cannot be divided by zero";
        return NAN; // Not a Number
    }
}

// Exceptional Handling

double modulo(int a, int b) {
    try {
        if (b == 0) {
            throw b;
        }
        else {
            return a%b;
        }
    }
    catch (int r) {
        cout<<"Exception caught : Invalid Argument for Modulus";
        return NAN; // Not a Number
    }
}

// Menu Driven Program

void printMenu() {
    cout<<"\n--------------------------------";
    cout<<"\n\nWelcome to Simple Calculator\n";
    cout<<"\nChoose one of the following operations\n";

    cout<<"\n1. Add";
    cout<<"\n2. Subtract";
    cout<<"\n3. Multiply";
    cout<<"\n4. Divide";
    cout<<"\n5. Modulus";
    cout<<"\n6. Power";
    cout<<"\n7. Exit";
    cout<<"\nNow, Enter your choice : ";
}

int main()
{
    int choice;
    double first, second, result;
    while(true) { // infinite loop
        printMenu();
        cin>>choice;
        if(choice == 7) { // Exit
            break;
        }

        if (choice < 1 || choice > 7) {
            cout<<"Invalid user choice";
            continue;
        }

        cout<<"\nPlease enter the first number : ";
        cin>>first;
        cout<<"Please enter the second number : ";
        cin>>second;

        switch (choice) {
            case 1: // Add
                result = first + second;
                break;
            case 2: // Subtract
                result = first - second;
                break;
            case 3: // Multiply
                result = first * second;
                break;
            case 4: // Divide
                result = division(first, second);
                break;
            case 5: // Modulus
                result = modulo(first, second);
                break;
            case 6: // Power
                result = pow(first, second);
                break;    
        }
        if (!isnan(result)) { // Checking for NAN 
            cout<<"\nResult of the operation is : "<<result;
        }
    }
    return 0;
}

// --------------------------------

// Welcome to Simple Calculator

// Choose one of the following operations

// 1. Add
// 2. Subtract
// 3. Multiply
// 4. Divide
// 5. Modulus
// 6. Power
// 7. Exit
// Now, Enter your choice : 4

// Please enter the first number : 4
// Please enter the second number :  

// Result of the operation is : 1.33333
// --------------------------------


// Welcome to Simple Calculator

// Choose one of the following operations

// 1. Add
// 2. Subtract
// 3. Multiply
// 4. Divide
// 5. Modulus
// 6. Power
// 7. Exit
// Now, Enter your choice : 7