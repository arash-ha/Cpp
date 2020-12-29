/*
Swap Nodes in Pairs
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

 

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
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
 // Solution 1
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head -> next) return head;
        ListNode* ptr1 = head -> next;
        ListNode* ptr2 = head -> next -> next;
        ptr1 -> next = head;
        head -> next = swapPairs(ptr2);
        return ptr1;       
    }
};

// Solution 2
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *ptr1 = head, *ptr2;
        head = head->next;
        while(ptr1 && ptr1->next){
            ptr2 = ptr1->next->next;
            ptr1->next->next = ptr1;
            if(!ptr2 || !(ptr2->next))
                ptr1->next = ptr2;
            else
                ptr1->next = ptr2->next;
            ptr1 = ptr2;
        }
        return head;
    }
};
