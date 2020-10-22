/*
Remove Duplicates from Sorted List

Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3

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
        
        if (!head) return head;
        
        ListNode* p1 = nullptr;
        ListNode* p2 = head;
        
        while(p2){
            if(!p1){
                p1 = p2;
                p2 = p2->next;
                continue;
            }
            
            if(p2->val == p1->val){
                p2 = p2->next;
                continue;
            }
            p1->next = p2;
            p1 = p2;
            p2 = p2->next;
            
        }
    
        p1->next = nullptr;
        return head;
    }
};
