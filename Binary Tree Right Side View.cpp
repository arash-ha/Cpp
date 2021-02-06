/*
Binary Tree Right Side View


Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> vec;
        vector<int> res;
        if(!root)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        int c = 1;
        while(!q.empty()){
            TreeNode* cur = q.front();
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
            vec.emplace_back(q.front()->val);
            q.pop();
            if(--c == 0){
                res.emplace_back(vec.back());
                vec.clear();
                c = q.size();
            }
        }
        return res;
    }
};
