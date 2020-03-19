/*
Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode *s;
        ListNode *new_head = NULL;
        
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1 && l2){
            if(l1->val <= l2->val){
                s = l1;
                l1 = s->next;
            }
            else{
                s = l2;
                l2 = s->next;
            }
            
        }
        new_head = s;
        
        while(l1 && l2){
            if(l1->val <= l2->val){
                s->next = l1;
                s = l1;
                l1 = s->next;
            }
            else{
                s->next = l2;
                s = l2;
                l2 = s->next;
            }
        }
        
        if(l1 == NULL) s->next = l2;
        if(l2 == NULL) s->next = l1;
        
        return new_head;
    }

};
