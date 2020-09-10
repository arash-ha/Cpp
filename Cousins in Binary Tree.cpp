/*
Cousins in Binary Tree
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:



Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            bool foundX = false;
            bool foundY = false;
            
            for(int i = 0; i < n; i++){
                TreeNode* cur = q.front();
                q.pop();
                if(cur -> val == x) foundX = true;
                if(cur -> val == y) foundY = true;
                
                if(cur -> left && cur -> right){
                    if((cur -> left -> val == x && cur -> right -> val == y) || (cur -> left -> val == y && cur -> right -> val == x)) return false;
                }
                if(cur -> left) q.push(cur -> left);
                if(cur -> right) q.push(cur -> right);
            }
            if (foundX && foundY) return true;
        }
        return false;
    }
};
