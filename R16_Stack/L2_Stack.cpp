#include <iostream>
#include <stack>
using namespace std;
int main()
{
    // How to get elements back in stack after printing or popping
    stack<int> st;
    stack<int> temp;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    cout<<st.size()<<endl;

    // We will use a extra stack
    // printing from top to bottom
    while(st.size() > 0) {
        cout<<st.top()<<" ";
        int x = st.top();
        temp.push(x);
        st.pop();
    }
    // 50 40 30 20 10 
    cout<<endl;

    // // printing from bottom to top
    // while(temp.size() > 0) {
    //     cout<<temp.top()<<" ";
    //     temp.pop();
    // }
    // cout<<endl;
    // // 10 20 30 40 50 

    // putting elements back in st from temp
    while(temp.size() > 0) {
        int x = temp.top();
        st.push(x);
        temp.pop();
    }

    // printing stack st again
    cout<<st.top()<<endl; // 50
    cout<<endl;
    return 0;
}