// Remove Nth Node From End of List
/*
The difference between the final node and the to_be_delete node is N. 
And here the assumption is that N is always valid.

fast pointer points to the node which is N step away from the to_be_delete node.

slow pointer points to the to_be_delete node.

The algorithms is described as below:

Firstly, move fast pointer N step forward.

Secondly,move fast and slow pointers simultaneously one step a time forward 
till the fast pointer reach the end, which will cause the slow pointer points to 
the previous node of the to_be_delete node.

Finally, slow->next = slow->next->next.
*/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node = head, *offsetNode = head;
        for (int i = 0; i < n; ++i)
            node = node->next;

        // if node is NULL n is equal to the length of the linked list and we have to remove the head
        if (node == NULL)
            return head->next;

        while (node->next != NULL) { // traverse to the last node in the linked list
            node = node->next;
            offsetNode = offsetNode->next;
        }

        ListNode *del = offsetNode->next; // del: the node that we want to delete
        offsetNode->next = offsetNode->next->next; // remove it
        delete del;
        return head;
    }
};