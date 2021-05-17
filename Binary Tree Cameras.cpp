/*
Binary Tree Cameras

Given a binary tree, we install cameras on the nodes of the tree. 
Each camera at a node can monitor its parent, itself, and its immediate children.
Calculate the minimum number of cameras needed to monitor all nodes of the tree.

Example 1:

Input: [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.

Example 2:

Input: [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.

Note:

The number of nodes in the given tree will be in the range [1, 1000].
Every node has value 0.
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
    int cam=0;
    unordered_set<TreeNode*> ust;
    int minCameraCover(TreeNode* root) {
        if(!root)
            return 0;
	    ust.insert(nullptr);
	    helper(root, nullptr);
        return cam;
    }
    void helper(TreeNode* node, TreeNode* parent){
	    if (node){
		    helper(node->left, node);
		    helper(node->right, node);
		    if (parent == nullptr && (ust.find(node) == ust.end()) || ust.find(node->left)== ust.end() || ust.find(node->right)== ust.end()){
			    cam++;
			    ust.insert(node);
			    ust.insert(parent);
			    ust.insert(node->left);
			    ust.insert(node->right);
            }
		}
	}
};
