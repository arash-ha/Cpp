/*
Binary Tree Level Order Traversal II
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        if(!root) return{};
        vector<int> v;
        vector<vector<int>> result;
        queue<TreeNode*> Q;
        Q.push(root);
        int c = 1;
        while(!Q.empty()){
            TreeNode* cur = Q.front();
            if(cur -> left) Q.push(cur -> left);
            if(cur -> right) Q.push(cur -> right);
            v.emplace_back(Q.front() -> val);
            Q.pop();
            if(--c == 0){
                result.emplace_back(v);
                v.clear();
                c = Q.size();
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
    
};
