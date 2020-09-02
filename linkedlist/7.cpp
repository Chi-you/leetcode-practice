/*
Merge two sorted linked lists and return it as a new sorted list.
The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        ListNode *tail = &dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2; // tail->next pointer points to the remaining linked list 
        return dummy.next;
    }
};

int main(){
    ListNode *l13 = new ListNode(6);
    ListNode *l12 = new ListNode(5, l13);
    ListNode *l1 = new ListNode(4, l12);
    ListNode *l23 = new ListNode(3);
    ListNode *l22 = new ListNode(2, l23);
    ListNode *l2 = new ListNode(1, l22);
    Solution s;
    ListNode *head = s.mergeTwoLists(l1, l2);
    while(head){
        cout<<head->val;
        head = head->next;
    }
}
