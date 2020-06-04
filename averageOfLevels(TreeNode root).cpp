/*
Average of Levels in Binary Tree
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.
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
    vector<double> averageOfLevels(TreeNode* root) {

        if(!root) return{};
        vector<int> v;
        vector<double> result;
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
                double sum = 0;
                for(int i = 0; i < v.size(); i++){
                    sum = sum + v[i];
                }
                double ave = sum / (v.size());
                result.emplace_back(ave);
                v.clear();
                c = Q.size();
            }
        }
        return result;
    }
};
