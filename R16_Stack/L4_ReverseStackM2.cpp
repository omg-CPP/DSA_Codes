// Using Array
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    int n = st.size();

    int arr[n];
    int i = 0;
    while(st.size() > 0) {
        cout<<st.top()<<" ";
        arr[i] = st.top();
        st.pop();
        i++;
    }
    // 50 40 30 20 10 
    cout<<endl;

    for(int i = 0 ; i < n ; i++) {
        cout<<arr[i]<<" ";
    }
    // 50 40 30 20 10 
    cout<<endl;

    for(int i = 0 ; i < n ; i++) {
        st.push(arr[i]);
    }

    while(st.size() > 0) {
        cout<<st.top()<<" ";
        st.pop();
    }
    // 10 20 30 40 50 
    cout<<endl;
    return 0;
}