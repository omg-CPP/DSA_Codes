// Leetcode : 2951

#include <iostream>
#include <vector>
using namespace std;

vector<int> findPeaks(vector<int>& mountain) {
    int n = mountain.size();
    vector<int> peaks;
    for(int i = 0 ; i < n ; i++) {
        if(i == 0 || i == n-1) {
            continue;
        }
        if(mountain[i] > mountain[i-1] && mountain[i] > mountain[i+1]) {
            peaks.push_back(i);
        }
    }
    return peaks;
}

int main() {
    vector<int> mountain = {1,4,3,8,5};
    vector<int> peaks = findPeaks(mountain);
    for(int i = 0 ; i < peaks.size() ; i++) {
        cout<<peaks[i]<<" ";
    }
    // 1 3
    cout<<endl;
    return 0;
}
