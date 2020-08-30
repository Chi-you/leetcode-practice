// linked list cycle II:
// Given a linked list, 
// return the node where the cycle begins. 
// If there is no cycle, return null.

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *entry = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                while(slow != entry){
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return NULL;

    }
};