// Leetcode : 2058

#include <iostream>
#include <vector>
#include <climits>
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

vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    // Calculating Maximum Distance
    int idx = 1;
    int fidx = -1;
    int sidx = -1;
    ListNode* a = head;
    ListNode* b = head->next;
    ListNode* c = head->next->next;

    if(c == NULL) {
        return {-1,-1};
    }

    while(c != NULL) {
        if((b->val > a->val && b->val > c->val) || (b->val < a->val && b->val < c->val)) {
            // local maxima or local minima
            if(fidx == -1) {
                fidx = idx;
            }
            else {
                sidx = idx;
            }
        }
        a = a->next;
        b = b->next;
        c = c->next;
        idx++;
    }
    if(sidx == -1) {
        return {-1,-1};
    }
    int maxD = sidx-fidx;

    // Calculating Minimum Distance
    int minD = INT_MAX;
    fidx = -1;
    sidx = -1;
    idx = 1;
    a = head;
    b = head->next;
    c = head->next->next;
    while(c != NULL) {
        if((b->val > a->val && b->val > c->val) || (b->val < a->val && b->val < c->val)) {
            // local maxima or local minima
            fidx = sidx;
            sidx = idx;
            if(fidx != -1) {
                int d = sidx - fidx;
                minD = min(minD,d);
            }
        }
        a = a->next;
        b = b->next;
        c = c->next;
        idx++;
    }
    return {minD,maxD};
}

int main()
{
    return 0;
}