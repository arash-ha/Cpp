/*
Symmetric Tree

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

Example 1:

Input: root = [1,2,2,3,4,4,3]
Output: true

Example 2:

Input: root = [1,2,2,null,3,null,3]
Output: false
 
Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return(isSymmetric_helper(root -> left, root -> right));
        
    }
    
    bool isSymmetric_helper(TreeNode *root1, TreeNode* root2){
        if (root1 == NULL && root2 == NULL) return true;
        if (root1 == NULL || root2 == NULL) return false;
        if (root1 -> val != root2 -> val) return false;
        return isSymmetric_helper(root1 -> left, root2 -> right) && isSymmetric_helper(root1 -> right, root2 -> left);
    }
};
