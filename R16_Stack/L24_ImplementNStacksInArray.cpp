#include<bits/stdc++.h> 
#include <iostream>
#include <stack>
using namespace std;
// Implement K Stacks in an Array with size = n

// T.C. : 
// O(1) for push operation
// O(1) for pop operation

// S.C. = O(n+k)

class NStack {

private : 
	vector<int> arr;
	int n,k;
	vector<int> top;
	vector<int> next;
	int freeIdx;

public :
	// constructor
	NStack(int n, int k) {
		this->n = n;
		this->k = k;
		arr.resize(n);
		top.resize(k,-1);
		next.resize(n);

		// next[] initialise
		for(int i = 0 ; i <= n-2 ; i++) {
			next[i] = i+1;
		}
		next[n-1] = -1;

		// initialise freeIdx
		freeIdx = 0;
	}

	// Pushes x into the mth stack
	// Returns true if x gets pushed else returns false
	bool push(int x, int m) {
		// x -> value to be pushed
		// m -> stack no

		// check for stack overflow 
		if(freeIdx == -1) {
			return false;
		}
		// find index
		int idx = freeIdx;
		// update freespot
		freeIdx = next[idx];
		// insert element
		arr[idx] = x;
		// update next : 0-based indexing
		next[idx] = top[m];
		// update top
		top[m] = idx;
		return true;
	}

	// Pops element from mth stack
	// Returns -1 if the stack is empty
	// Otherwise return the popped element
	int pop(int m) {
		// m -> stack no

		// check for stack underflow : Stack is empty
		if(top[m] == -1) {
			return -1;
		}
		// find index
		int idx = top[m]; // 2
		// update top
		top[m] = next[idx]; // 1
		// update next and freeIdx
		next[idx] = freeIdx;
		// assigning freeIdx = idx as the position in array is free
		freeIdx = idx;
		// Return the popped element
		return arr[idx];
	}
};

int main() 
{
	int n = 9;
	int k = 3;
	NStack st(n,k);
	cout<<st.pop(0)<<endl; // -1 : Stack Underflow
	cout<<st.pop(1)<<endl; // -1 : Stack Underflow
	cout<<st.pop(2)<<endl; // -1 : Stack Underflow
	cout<<st.push(100,0)<<endl; // 1 
	cout<<st.push(200,0)<<endl; // 1
	cout<<st.push(10,1)<<endl; // 1
	cout<<st.push(20,1)<<endl; // 1
	cout<<st.push(1,2)<<endl; // 1
	cout<<st.push(2,2)<<endl; // 1
	cout<<st.push(3,2)<<endl; // 1
	cout<<st.push(4,2)<<endl; // 1
	cout<<st.push(5,2)<<endl; // 1
	cout<<st.push(6,2)<<endl; // 0 : Stack Overflow
	cout<<st.pop(0)<<endl; // 200
	cout<<st.pop(1)<<endl; // 20
	cout<<st.pop(2)<<endl; // 5
	return 0;
}
