/*
Remove Duplicates from Sorted List II
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Return the linked list sorted as well.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* p1 = &dummy;
        ListNode* p2 = dummy.next;
        while(p2 && p2->next){
            if(p1->next->val == p2->next->val){
                while(p2->next && p1->next->val == p2->next->val)
                    p2 = p2->next;
                p1->next = p2->next;
                p2 = p2->next;
            }
            else{
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        return dummy.next;
    }
};
