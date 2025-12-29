// Leetcode 23
// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ListNode {
public :
    int value;
    ListNode* next;

    ListNode(int value) {
        this->value = value;
        this->next = NULL;
    }
};

// T.C. : K lists with each has n elements : O(n * k(k+1)/2 - n) = O(n*k^2)

ListNode* merge(ListNode* a, ListNode* b) {
    ListNode* c = new ListNode(100);
    ListNode* temp = c;
    while(a != NULL && b != NULL) {
        if(a->value <= b->value) {
            temp->next = a;
            a = a->next;
            temp = temp->next;
        }
        else { // a->value > b->value
            temp->next = b;
            b = b->next;
            temp = temp->next;
        }
    }
    if(a == NULL) {
        temp->next = b;
    }
    else { // b == NULL
        temp->next = a;
    }
    return c->next;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.size() == 0) {
        return NULL;
    }
    while(lists.size() > 1) {
        ListNode* a = lists[lists.size()-1];
        lists.pop_back();
        ListNode* b = lists[lists.size()-1];
        lists.pop_back();
        ListNode* m = merge(a,b);
        lists.push_back(m);
    }
    return lists[0];
}

// T.C. = O(n*klogk)  
// S.C. = O(k)
ListNode* mergeKListsOptimal(vector<ListNode*>& lists) {
    if(lists.size() == 0) {
        return NULL;
    }
    while(lists.size() > 1) {
        ListNode* a = lists[0];
        // pop front
        lists.erase(lists.begin());
        ListNode* b = lists[0];
        // pop front
        lists.erase(lists.begin());
        ListNode* m = merge(a,b);
        lists.push_back(m);
    }
    return lists[0];
}


int main()
{
    return 0;
}