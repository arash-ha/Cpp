/*
Maximum Difference Between Node and Ancestor
 Given the root of a binary tree, find the maximum value V for which there exists different nodes A and B where V = |A.val - B.val| and A is an ancestor of B.

(A node A is an ancestor of B if either: any child of A is equal to B, or any child of A is an ancestor of B.)

 

Example 1:



Input: [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: 
We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.
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
    int maxAncestorDiff(TreeNode* root) {
        int max = INT_MIN;
        int min = INT_MAX;
        int cur = INT_MIN;
        helper(root, max, min, cur);
        return cur;
    }
    void helper(TreeNode* root, int max, int min, int& cur){

        max = max > root -> val ? max : root -> val;
        min = min < root -> val ? min : root -> val;
        
        if(!root -> left && !root -> right){
            cur = max - min > cur ? max - min : cur;
        }
        
        if(root -> left) helper(root -> left, max, min, cur);
        if(root -> right) helper(root -> right, max, min, cur);
    }
};
