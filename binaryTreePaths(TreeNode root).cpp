/*
Binary Tree Paths
Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
    vector<string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> v{};
        string s{};
        if(root) helper(v, root, s);
        return v;
    }
    void helper(vector<string>& v, TreeNode* root, string s){
        if(!root) return;
        if(!s.empty()) s += ("->" + to_string(root -> val));
        else s += (to_string(root -> val));
        if(root -> left || root -> right){
            helper(v, root -> left, s);
            helper(v, root -> right, s);
        }
        else v.emplace_back(s);
    }
    
};
