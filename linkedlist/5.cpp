// ***Remove all elements from a linked list of integers that have value val

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        for (ListNode* node = dummy; node != nullptr; node = node->next) {
            while (node->next != nullptr && node->next->val == val) {
                node->next = node->next->next;
            }
        }
        head = dummy->next; // due to node points to dummy at first, while node changes the node that it points to, and dummy either
        delete dummy;
        return head;
    }
};

// int main(){
//     Solution s;
//     ListNode *second = new ListNode(2);
//     ListNode *head = new ListNode(1, second);
//     ListNode *cur = s.removeElements(head, 1);
//     while(cur){
//         cout<<cur->val;
//         cur = cur->next;
//     }
// }