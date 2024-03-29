/*
Longest Univalue Path

Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.
The length of path between two nodes is represented by the number of edges between them.

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output: 2

Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output: 2

Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.
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
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        int count_longest = 0;
        helper(root, count_longest);
        return count_longest;
        
    }
    int helper(TreeNode* root, int& c){
        int left, right;
        if(root -> left) left = helper(root -> left, c);
        else left = 0;
        if(root -> right) right = helper(root -> right, c);
        else right = 0;
        if(root -> left && root -> left -> val == root -> val) left++;
        else left = 0;
        if(root -> right && root -> right -> val == root -> val) right++;
        else right = 0;
        c = max(c, left + right);
        return max(left, right);
    }
};
