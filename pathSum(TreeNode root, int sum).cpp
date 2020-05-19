/*
Path Sum II
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == NULL) return result;
        vector<int> tmp;
        helper(root, tmp, 0, sum);
        return result;
    }
private:
    vector<vector<int>> result;
    
    void helper(TreeNode* root, vector<int> tmp, int cur, int sum){
        if(!root) return;
        tmp.emplace_back(root -> val);
        if(!root -> left && !root -> right && cur + root -> val == sum){
            result.emplace_back(tmp);
            return;
        }
        helper(root -> left, tmp, cur + root -> val, sum);
        helper(root -> right, tmp, cur + root -> val, sum);
    }
    
};
