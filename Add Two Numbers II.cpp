/*
Add Two Numbers II

You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1 = listToStack(l1);
        stack<int> st2 = listToStack(l2);
        
        int carry = 0;
        ListNode* head = nullptr;
            
        while (!st1.empty() || !st2.empty() || carry) {
            int num1 = st1.empty() ? 0 : st1.top();
            if (!st1.empty()) st1.pop();
            int num2 = st2.empty() ? 0 : st2.top();
            if (!st2.empty()) st2.pop();
            int sum = num1 + num2 + carry;
        
            ListNode *newNode = new ListNode(sum % 10);
        
            newNode->next = head;
            head = newNode;
            carry = sum/10;
            l1 = l1? l1->next : nullptr;
            l2 = l2? l2->next : nullptr;
        }
        return head;
    }
    stack<int> listToStack(ListNode* h){
        stack<int> st;
        while(h){
            st.push(h->val);
            h = h->next;
        }
        return st;
    }
};
