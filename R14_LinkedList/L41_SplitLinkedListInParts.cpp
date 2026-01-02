// Leetcode : 725

#include <iostream>
#include <vector>
using namespace std;

class ListNode {
public:
    int val;   
    ListNode* next;

    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

vector<ListNode*> splitListToParts(ListNode* head, int k) {
    // No of parts = k
    // length of parts can be either n/k or (n/k)+1 or 0
    // calculate size of linked list
    int n = 0;
    ListNode* t = head;
    while(t != NULL) {
        t = t->next;
        n++;
    }
    // breaking the list into k lists
    // n = 11 && k = 3
    vector<ListNode*> ans;
    int size = n/k;
    int rem = n % k;
    ListNode* temp = head;
    while(temp != NULL) {
        ListNode* c = new ListNode(100);
        ListNode* tempC = c;
        int s = size;
        if(rem > 0) {
            s++;
        }
        rem--;
        for(int i = 1 ; i <= s ; i++) {
            tempC->next = temp;
            temp = temp->next;
            tempC = tempC->next;
        }
        tempC->next = NULL; // linked list breaking into parts
        ans.push_back(c->next);
    }
    if(ans.size() < k) {
        int extra = k - ans.size();
        for(int i = 1 ; i <= extra ; i++) {
            ans.push_back(NULL);
        }
    }
    return ans;
}

int main()
{
    return 0;
}