/*
Convert Sorted Array to Binary Search Tree
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
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
    using iter = vector<int>::const_iterator;
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty())
            return nullptr;
        return BST(nums.begin(), nums.end());
    }
    
    TreeNode* BST(iter l, iter r){
        if (l < r){
            iter m = l + (r - l) / 2;
            TreeNode* root = new TreeNode(*m);
            root->left = BST(l, m);
            root->right = BST(m + 1, r);
            return root;
        }
        return nullptr;
    }
};
