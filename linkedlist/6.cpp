/*
Given a singly linked list, group all odd nodes together followed by the even nodes. 
Please note here we are talking about the node number and not the value in the nodes.
*/

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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;

        auto odd = head, evenHead = head->next, even = evenHead;
        while (even && even->next) {
            odd = odd->next = even->next;
            even = even->next = odd->next;
        }
        odd->next = evenHead;

        return head;
    }
};