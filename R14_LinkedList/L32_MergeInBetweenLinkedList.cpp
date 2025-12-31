// Leetcode 1669

#include <iostream>
using namespace std;

class ListNode {
public : 
    int val;
    ListNode* next;

    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode* preA = list1;
    // Move at index a-1
    for(int i = 1 ; i <= a-1 ; i++) { // suppose a = 3 => a-1 = 2 => Loop goes 1 to 2
        preA = preA->next;
    }

    ListNode* postB = preA;
    for(int i = 1 ; i <= b-a+2 ; i++) { // (b+1) - (a-1) = (b-a+2)
        postB = postB->next;
    }

    // connect preA to list2 head
    preA->next = list2;

    ListNode* temp = list2;
    // traverse on list2
    while(temp->next != NULL) {
        temp = temp->next;
    }
    // connect last node of list2 i.e. temp to postB
    temp->next = postB;
    
    // return final updated list1
    return list1;
}

int main()
{
    return 0;
}