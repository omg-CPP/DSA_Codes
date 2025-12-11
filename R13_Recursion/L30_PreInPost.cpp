#include <iostream>
using namespace std;

// refer to notes :
// 1) Euler Tree Method : Pre In Post Method
// 2) Call Stack Method

void PreInPost(int n) {
    // base case
    if(n == 0) {
        return;
    }
    cout<<"Pre "<<n<<endl;
    PreInPost(n-1);
    cout<<"In "<<n<<endl;
    PreInPost(n-1);
    cout<<"Post "<<n<<endl;
}
int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    PreInPost(n);
    return 0;
}

// Enter n : 3
// Pre 3
// Pre 2
// Pre 1
// In 1
// Post 1
// In 2
// Pre 1
// In 1
// Post 1
// Post 2
// In 3
// Pre 2
// Pre 1
// In 1
// Post 1
// In 2
// Pre 1
// In 1
// Post 1
// Post 2
// Post 3

// Enter n : 2
// Pre 2
// Pre 1
// In 1
// Post 1
// In 2
// Pre 1
// In 1
// Post 1
// Post 2