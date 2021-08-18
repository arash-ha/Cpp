/*
Unique Binary Search Trees II

Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

Example 1:

Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]

Example 2:

Input: n = 1
Output: [[1]]
 
Constraints:

1 <= n <= 8
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
    vector<TreeNode*> generateTrees(int n) {
        if(!n) 
            return vector<TreeNode*>();
        return helper(1, n);
    }
    vector<TreeNode*> helper(int low, int high){
        vector<TreeNode*> vec;
        if(low > high){
            vec.emplace_back(nullptr);
            return vec;
        }
        for(int i = low; i <= high; i++){
            auto left = helper(low, i - 1);
            auto right = helper(i + 1, high);
            for(auto l : left){
                for(auto r : right){
                    TreeNode* cur = new TreeNode(i, l, r);
                    vec.emplace_back(cur);
                }
            }
        }
        return vec;
    }
};
