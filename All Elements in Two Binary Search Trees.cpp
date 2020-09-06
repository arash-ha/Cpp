/*
All Elements in Two Binary Search Trees
Given two binary search trees root1 and root2.

Return a list containing all the integers from both trees sorted in ascending order.

 

Example 1:


Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]
Example 2:

Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
Output: [-10,0,0,1,2,5,7,10]
Example 3:

Input: root1 = [], root2 = [5,1,7,0,2]
Output: [0,1,2,5,7]
Example 4:

Input: root1 = [0,-10,10], root2 = []
Output: [-10,0,10]
Example 5:


Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]
 

Constraints:

Each tree has at most 5000 nodes.
Each node's value is between [-10^5, 10^5].
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        stack<TreeNode*> s1, s2;
        while(root1 || root2 || !s1.empty() || !s2.empty()){
            while(root1){
                s1.push(root1);
                root1 = root1 -> left;
            }
            while(root2){
                s2.push(root2);
                root2 = root2 -> left;
            }
            if(s2.empty() || (!s1.empty() && s1.top() -> val <= s2.top() -> val)){
                root1 = s1.top();
                s1.pop();
                res.push_back(root1 -> val);
                root1 = root1 -> right;
            }
            else{
                root2 = s2.top();
                s2.pop();
                res.push_back(root2 -> val);
                root2 = root2 -> right;
            }
        }
        return res;
    }
};
