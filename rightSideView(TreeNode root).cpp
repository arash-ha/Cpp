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
        vector<int> v;
        vector<int> result;
        if(!root) return result;
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
                result.emplace_back(v.back());
                v.clear();
                c = Q.size();
            }
        }
        return result;
    }
};
