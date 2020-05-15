/*
Minimum Absolute Difference in BST
Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
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
