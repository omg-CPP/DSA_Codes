#include <iostream>
#include <vector>
using namespace std;

// 3 Sorted Arrays : Three Pointers
vector<int> commonElements(vector<int>& a, vector<int>& b, vector<int>& c) {
    vector<int> ans;
    int n1 = a.size();
    int n2 = b.size();
    int n3 = c.size();
    int i = 0, j = 0, k = 0;
    while(i < n1 && j < n2 && k < n3) {
        if((a[i] == b[j]) && (b[j] == c[k])) {
            ans.push_back(a[i]);
            i++, j++, k++;
        }
        else if((a[i] < b[j]) || (a[i] < c[k])) {
            i++;
        }
        else if((b[j] < a[i]) || (b[j] < c[k])) {
            j++;
        }
        else if((c[k] < a[i]) || (c[k] < b[j])) {
            k++;
        }
    }
    return ans;
}
int main()
{
    vector<int> v1 = {1,5,10,20,40,80};
    vector<int> v2 = {6,7,20,80,100};
    vector<int> v3 = {3,4,15,20,30,70,80,120};
    vector<int> common = commonElements(v1,v2,v3);
    for(int i = 0 ; i < common.size() ; i++) {
        cout<<common[i]<<" ";
    }
    // 20 80 
    cout<<endl;
    return 0;
}