/*
Reverse Linked List

Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        struct ListNode *p1,*p2,*p3;
        
        if (head == NULL) return 0;
        if (head -> next == NULL) return head;
        
        p1 = head;
        p2 = p1 -> next;
        p3 = p2 -> next;
        p1 -> next = NULL;
        p2 -> next = p1;
        
        while(p3 != NULL){
            p1 = p2;
            p2 = p3;
            p3 = p3 -> next;
            p2 -> next = p1;
        }
        head = p2;
        return head;
    }
};
