// Leetcode : 1733

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        // low constraints in the problem
        
        // steps : 
        unordered_set<int> sadUsers;
        for(auto& friends : friendships) {
            // converting to 0-based indexing
            int u = friends[0] - 1;
            int v = friends[1] - 1;

            unordered_set<int> langSet(begin(languages[u]),end(languages[u]));
            
            bool canTalk = false;
            for(auto& i : languages[v]) {
                if(langSet.count(i)) {
                    canTalk = true;
                    break;
                }
            }

            if(!canTalk) {
                sadUsers.insert(u);
                sadUsers.insert(v);
            }
        }

        if(sadUsers.empty()) {
            return 0;
        }
        
        // Count how many languages do each sadUser know
        vector<int> languageCount(n+1,0);   // languages are 1-indexed
        for(auto user : sadUsers) {
            for(auto& lang : languages[user]) {
                languageCount[lang]++;
            }
        }
        // Find the most popular language among sad users
        int mostPopularCount = 0;
        for(int i = 1 ; i <= n ; i++) {
            mostPopularCount = max(mostPopularCount, languageCount[i]);
        }
        return sadUsers.size() - mostPopularCount;
    }
};

int main()
{
    Solution s;
    int n = 3;
    vector<vector<int>> languages = {{2},{1,3},{1,2},{3}};
    vector<vector<int>> friendships = {{1,4},{1,2},{3,4},{2,3}};
    cout<<s.minimumTeachings(n,languages,friendships)<<endl;  // Output : 2
    return 0;
}