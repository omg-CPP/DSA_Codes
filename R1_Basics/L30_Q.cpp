#include <iostream>
using namespace std;
int main()
{
    int i = 2 * 3 / 4 + 4 / 4 + 8 - 2 + 5 / 8;
    // left to right
    // 6 / 4 + 1 + 8 - 2 + 0
    // 1 + 1 + 8 - 2 
    // 8
    cout<<i<<endl;

    // Precedency Of Operators : Highest To Lowest

    // [],()                    @ L->R
    // Unary -> ++ --           
    // * / %                    @ L->R
    // + -                      @ L->R
    // << >> >>> -> Shift       @ L->R
    // Relational -> <= >= < >  @ L->R
    // Equality -> == !=        @ L->R
    // &                        @ L->R
    // ^                        @ L->R
    // |                        @ L->R
    // &&                       @ L->R
    // ||                       @ L->R
    // Conditional -> ?:        @ R->L
    // Assignment -> = , += , -= , *= , /= , etc  @ R->L

    return 0;
}