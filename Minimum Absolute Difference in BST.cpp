/*
Minimum Absolute Difference in BST

Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

Example 1:

Input: root = [4,2,6,1,3]
Output: 1

Example 2:

Input: root = [1,0,48,null,null,12,49]
Output: 1
 
Constraints:

The number of nodes in the tree is in the range [2, 10^4].
0 <= Node.val <= 10^5
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
    int min_dif = INT_MAX, prev = -1;
public:
    int getMinimumDifference(TreeNode* root) {
        if(root == NULL) return min_dif;
        getMinimumDifference(root -> left);
        if(prev >= 0) min_dif = min(min_dif, root -> val - prev);
        prev = root -> val;
        getMinimumDifference(root -> right);
        return min_dif;

    }
};
