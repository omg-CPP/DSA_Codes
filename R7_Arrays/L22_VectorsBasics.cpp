#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v; // you need not mention size

    cout<<v.size()<<endl; // 0
    cout<<v.capacity()<<endl; // 0

    v.push_back(6);
    cout<<v.size()<<endl; // 1
    cout<<v.capacity()<<endl; // 1

    v.push_back(1);
    cout<<v.size()<<endl; // 2
    cout<<v.capacity()<<endl; // 2

    v.push_back(9);
    cout<<v.size()<<endl; // 3
    cout<<v.capacity()<<endl; // 4

    v.push_back(0);
    cout<<v.size()<<endl; // 4
    cout<<v.capacity()<<endl; // 4

    v.push_back(8);
    cout<<v.size()<<endl; // 5
    cout<<v.capacity()<<endl; // 8

    cout<<v[0]<<" ";
    cout<<v[1]<<" ";
    cout<<v[2]<<" ";
    cout<<v[3]<<" ";
    cout<<v[4]<<" ";
    // 6 1 9 0 8

    cout<<endl;

    for(int i = 0 ; i < v.size() ; i++) {
        cout<<v[i]<<" ";
    }
    // 6 1 9 0 8 

    cout<<endl;

    vector<int> vec;

    vec.push_back(6);
    vec.push_back(1);
    vec.push_back(9);
    vec.push_back(10);
    vec.push_back(9);
    vec.push_back(10);
    vec.push_back(1);
    vec.push_back(9);
    vec.push_back(10);
    vec.push_back(9);
    vec.push_back(10);

    cout<<vec.size()<<endl; // 11
    cout<<vec.capacity()<<endl; // 16

    for(int i = 0 ; i < vec.size() ; i++) {
        cout<<vec[i]<<" ";
    }
    // 6 1 9 10 9 10 1 9 10 9 10 
    cout<<endl;

    cout<<vec.size()<<endl; // 11
    cout<<vec.capacity()<<endl; // 16

    vec.pop_back();
    vec.pop_back();

    for(int i = 0 ; i < vec.size() ; i++) {
        cout<<vec[i]<<" ";
    }
    // 6 1 9 10 9 10 1 9 10
    cout<<endl;

    cout<<vec.size()<<endl; // 9
    cout<<vec.capacity()<<endl; // 16 


    // Vector with size
    vector<int> vect(5); // declaration and initialisation
    cout<<vect.size()<<endl; // 5
    cout<<vect.capacity()<<endl; // 5

    for(int i = 0 ; i < vect.size() ; i++) {
        cout<<vect[i]<<" ";
    }
    // 0 0 0 0 0 
    cout<<endl;

    vector<int> vi(5,7);
    cout<<vi.size()<<endl; // 5
    cout<<vi.capacity()<<endl; // 5

    for(int i = 0 ; i < vi.size() ; i++) {
        cout<<vi[i]<<" ";
    }
    // 7 7 7 7 7
    cout<<endl;

    return 0;
} 