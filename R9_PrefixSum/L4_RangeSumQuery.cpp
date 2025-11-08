#include <iostream>
#include <vector>
using namespace std;

// Range Sum Queery - Immutable : Leetcode 303
// An immutable value is one whose content cannot be changed without creating an entirely new value

// class declaration and initialisation
class NumArray {
    public:

    vector<int> prefix; // vector initialised outside function to be accessed by other functions.
    
    // Constructor to create a prefix sum array
    NumArray(vector<int>& nums) { // parameterised constructor
        int n = nums.size();
        prefix = vector<int>(n);
        prefix[0] = nums[0];
        for(int i = 1 ; i < n ; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }
    }
    
    // actual function to find range sum query
    int sumRange(int left, int right) {
        if(left == 0) {
            return prefix[right];
        }
        else {
            return prefix[right] - prefix[left-1];
        }
    }
};

int main()
{
    vector<int> v = {-2,0,3,-5,2,-1};
    for(int i = 0 ; i < v.size() ; i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    NumArray numArray(v); // calling of parameterised constructor

    int left;
    cout<<"Enter left index : ";
    cin>>left;
    int right;
    cout<<"Enter right index : ";
    cin>>right;

    int rangeSum = numArray.sumRange(left,right); // calling function inside class using object of the class

    cout<<"The Sum from index "<<left<<" to index "<<right<<" is : "<<rangeSum<<endl;
    return 0;
}

// -2 0 3 -5 2 -1 

// Enter left index : 0
// Enter right index : 2
// The Sum from index 0 to index 2 is : 1

// Enter left index : 2
// Enter right index : 5
// The Sum from index 2 to index 5 is : -1

// Enter left index : 0
// Enter right index : 5
// The Sum from index 0 to index 5 is : -3