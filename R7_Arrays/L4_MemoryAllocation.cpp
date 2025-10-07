#include <iostream>
using namespace std;
int main()
{
    int arr[5];
    cout<<&arr[0]<<endl; // 0x61fefc (fc)
    cout<<&arr[1]<<endl; // 0x61ff00 (00)
    cout<<&arr[2]<<endl; // 0x61ff04 (04)
    cout<<&arr[3]<<endl; // 0x61ff08 (08)
    cout<<&arr[4]<<endl; // 0x61ff0c (0c)

    cout<<&arr<<endl; // 0x61fefc : &arr[0] == &arr

    int nums[3] = {1,3,5};
    cout<<nums<<endl; // 0x61fef0
    cout<<&nums[0]<<endl; // 0x61fef0
    cout<<&nums<<endl; // 0x61fef0
    return 0;
}

// PS C:\Users\hp\OneDrive\Desktop\DSA\R7_ARRAYS> g++ L4_MemoryAllocation.cpp -o MemoryAllocation
// PS C:\Users\hp\OneDrive\Desktop\DSA\R7_ARRAYS> ./MemoryAllocation.exe

// 0x61fefc
// 0x61ff00
// 0x61ff04
// 0x61ff08
// 0x61ff0c
// 0x61fefc