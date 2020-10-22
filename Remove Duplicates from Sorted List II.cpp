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
        if(head == NULL) return head;
        
        ListNode dummyHead(-1);
        dummyHead.next = head;
        ListNode* ptr1 = &dummyHead;
        ListNode* ptr2 = dummyHead.next;
        
        while(ptr2 != NULL && ptr2->next != NULL){
            if(ptr1->next->val == ptr2->next->val){
                while(ptr2->next != NULL && ptr1->next->val == ptr2->next->val){
                    ptr2 = ptr2->next;
                }
                ptr1->next = ptr2->next;
                ptr2 = ptr2->next;
            }
            else{
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
        }
        return dummyHead.next;
    }
};
