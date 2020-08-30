// Reverse Linked List
#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = new ListNode(0);
        ListNode *cur = head; // cur always point to the first element in the original linked list
        pre->next = head;
        // while condition: the LHS must be check for null
        while(cur && cur->next){ // check if cur->next becomes NULL
            ListNode *temp = head; // temp always points to head pointer 
            head = cur->next;
            cur->next = cur->next->next;
            head->next = temp;
        }
        return head;
    }
};