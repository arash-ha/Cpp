/*
Reverse Linked List II
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 = m = n = length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || !head -> next) return head;
        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode* p1 = dummy;
        for (int i = 1; i < m; i++, p1 = p1 -> next);
        ListNode* p2 = p1;
        p1 = p1 -> next;
        ListNode* p3 = p1 -> next;
        for(int i = m; i < n; i++){
            p1 -> next = p3 -> next;
            p3 -> next = p2 -> next;
            p2 -> next = p3;
            p3 = p1 -> next;
        }
        return dummy -> next;
    }
};
