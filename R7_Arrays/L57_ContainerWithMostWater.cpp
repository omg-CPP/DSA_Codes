#include <iostream>
#include <vector>
using namespace std;

int maxAreaBruteForce(vector<int>& height) {
    int n = height.size();
    int maxWater = 0;
    for(int i = 0 ; i < n ; i++) {
        for(int j = i+1 ; j < n ; j++) {
            int wid = j-i;
            int ht = min(height[i],height[j]);
            int currWater = wid * ht;
            maxWater = max(maxWater,currWater);
        }
    }
    return maxWater;
}

int maxArea(vector<int>& height) {
    int n = height.size();
    int lp = 0;
    int rp = n-1;
    int maxWater = 0;
    while(lp < rp) {
        int w = rp-lp;
        int h = min(height[lp],height[rp]);
        int currWater = w * h;
        maxWater = max(maxWater,currWater);
        if(height[lp] < height[rp]) {
            lp++;
        }
        else { // height[lp] > height[rp]
            rp--;
        }
        // height[lp] < height[rp] ? lp++ : rp--;
    }
    return maxWater;
}

int main()
{
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    int area = maxAreaBruteForce(height);
    cout<<area<<endl; // 49
    int water = maxArea(height);
    cout<<water<<endl; // 49
    return 0;
}