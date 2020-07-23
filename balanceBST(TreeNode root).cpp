/*
Balance a Binary Search Tree
Given a binary search tree, return a balanced binary search tree with the same node values.

A binary search tree is balanced if and only if the depth of the two subtrees of every node never differ by more than 1.

If there is more than one answer, return any of them.

 

Example 1:



Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2,null,null] is also correct.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> sortedArray;
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return sortedArrayToBST(0, sortedArray.size() - 1);
    }
    
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root -> left);
        sortedArray.emplace_back(root);
        inorder(root -> right);
    }
    
    
    TreeNode* sortedArrayToBST(int left, int right){
        if (left > right) return nullptr;
        int mid = left + (right - left)/2;
        TreeNode* current = sortedArray[mid];
        current -> left = sortedArrayToBST(left, mid - 1);
        current -> right = sortedArrayToBST(mid + 1, right);
        return current;
    }
};
