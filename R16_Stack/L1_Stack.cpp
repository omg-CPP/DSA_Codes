#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> st;
    cout<<st.size()<<endl; // 0
    st.push(10);
    cout<<st.size()<<endl; // 1
    st.push(20);
    cout<<st.size()<<endl; // 2
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    cout<<st.size()<<endl; // 6

    st.pop();
    cout<<st.size()<<endl; // 5

    cout<<st.top()<<endl; // 50

    // printing elements of stack in reverse order
    // problem : stack becomes empty
    while(st.size() > 0) {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    // 50 40 30 20 10 

    return 0;
}