#include <iostream>
#include <stack>
using namespace std;

// void display(stack<int> st) {
//     while(st.size() > 0) {
//         cout<<st.top()<<" ";
//         st.pop();
//     }
//     cout<<endl;
// }

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    stack<int> temp1;
    stack<int> temp2;

    // Using two extra stacks

    while(st.size() > 0) {
        cout<<st.top()<<" ";
        int x = st.top();
        temp1.push(x);
        st.pop();
    }
    // st : 50 40 30 20 10 
    cout<<endl;

    while(temp1.size() > 0) {
        cout<<temp1.top()<<" ";
        int x = temp1.top();
        temp2.push(x);
        temp1.pop();
    }
    // 10 20 30 40 50 
    cout<<endl;

    while(temp2.size() > 0) {
        cout<<temp2.top()<<" ";
        int x = temp2.top();
        st.push(x);
        temp2.pop();
    }
    // 50 40 30 20 10 
    cout<<endl;

    while(st.size() > 0) {
        cout<<st.top()<<" ";
        st.pop();
    }
    // st : 10 20 30 40 50 

    // display(st); // 10 20 30 40 50 
    // cout<<endl;
    return 0;
}