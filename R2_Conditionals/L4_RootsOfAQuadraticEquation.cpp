#include <iostream>
#include <algorithm>
#include <Math.h>
#include <cmath>
using namespace std;
bool RootsOfQuadraticEqn(float a, float b, float c)
{
    float D,x1,x2;
    D = b*b - 4*a*c;
    if(a == 0)
    {
        cout<<"Not a Quadratic Equation";
        return false;
    }
    if(D > 0)
    {
        cout<<"Roots are Real and Distinct in Nature"<<endl;
        x1 = (-b + sqrt(D))/(2*a);
        x2 = (-b - sqrt(D))/(2*a);
        cout<<"Roots are : "<<x1<<" and "<<x2<<endl;
        return true;
    }
    else if(D == 0)
    {
        cout<<"Roots are Real and Equal in Nature"<<endl;
        x1 = -b/(2*a);
        x2 = -b/(2*a);
        cout<<"Roots are : "<<x1<<" and "<<x2<<endl;
        return true;
    }
    else // D < 0
    {
        cout<<"Roots are Imaginary in Nature"<<endl;
        cout<<"x1 : "<<-b/(2*a)<<" + "<<sqrt(abs(D))/(2*a)<<" i"<<endl;
        cout<<"x2 : "<<-b/(2*a)<<" - "<<sqrt(abs(D))/(2*a)<<" i"<<endl;
        return true;
    }
}
int main()
{
    // General Information before CODE 
    // if f(x) = ax^2 + bx + c = 0 is Quadratic Equation
    // where a, b, c, ∈ R and a ≠ 0.
    // Then Roots are calculated as x = (-b ± √D)/2a
    // where D = b*c*c - 4*a*c
    // if D > 0 => Roots are Real and Distinct in Nature.
    // if D = 0 => Roots are Real and Equal in Nature.
    // if D < 0 => Roots are Imaginary in Nature (Exist In Pairs).

    float a,b,c;
    cout<<"Enter a, b and c : ";
    cin>>a>>b>>c;
    if(RootsOfQuadraticEqn(a,b,c)) // i.e. TRUE
    {
        cout<<"Roots Fetched Successfully";
    }
    else // i.e. FALSE
    {
        cout<<" : ERROR";
    }
    return 0;
}

// Enter a, b and c : 1 1 1
// Roots are Imaginary in Nature
// x1 : -0.5 + 0.866025 i
// x2 : -0.5 - 0.866025 i
// Roots Fetched Successfully

// Enter a, b and c : 1 2 1
// Roots are Real and Equal in Nature
// Roots are : -1 and -1
// Roots Fetched Successfully

// Enter a, b and c : 1 -7 -12
// Roots are Real and Distinct in Nature
// Roots are : 8.42443 and -1.42443
// Roots Fetched Successfully

// Enter a, b and c : 1 7 10
// Roots are Real and Distinct in Nature
// Roots are : -2 and -5
// Roots Fetched Successfully

// Enter a, b and c : 1 -4 4
// Roots are Real and Equal in Nature
// Roots are : 2 and 2
// Roots Fetched Successfully

// Enter a, b and c : 0 0 2
// Not a Quadratic Equation : ERROR

// Enter a, b and c : 0 2 -4
// Not a Quadratic Equation : ERROR

