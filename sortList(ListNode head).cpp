/*
Sort a linked list in O(n log n) time using constant space complexity.
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
    ListNode* merge(ListNode* p1, ListNode* p2){
        ListNode dummy(0);
        ListNode *c = &dummy;
        while(p1 != NULL && p2 != NULL){
            if (p1->val > p2->val){
                c->next = p2;
                p2 = p2->next;
            }
            else{
                c->next = p1;
                p1 = p1->next;
            }
            c = c->next;
        }
        if(p1 != NULL) c->next = p1;
        else if(p2 != NULL) c->next = p2;
        return dummy.next;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        while(p2->next != NULL){
            p1 = p1->next;
            p2 = p2->next;
            if(p2->next != NULL) p2 = p2->next;
        }
        p2 = p1->next;
        p1->next = NULL;
        p2 = sortList(p2);
        p1 = sortList(head);
        head = merge(p1, p2);
        return head;
    }
};
