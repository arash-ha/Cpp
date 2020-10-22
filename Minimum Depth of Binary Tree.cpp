/*
Minimum Depth of Binary Tree
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.
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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        vector<int> v;
        helper(root, 0, v);
        int min = v[0];
        for(int i = 0; i < v.size(); i++){
            if(v[i] < min) min = v[i];
        }
        return min;
    }
    void helper(TreeNode* root, int c, vector<int>& v){
        if(!root) return;
        c++;
        if(!root -> left && !root -> right){
            v.emplace_back(c);
            c = 0;
        }
        helper(root -> left, c, v);
        helper(root -> right, c, v);
    }
};
