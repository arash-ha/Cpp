/*
Maximum Width of Binary Tree

Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.
The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

Example 1:

Input: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).

Example 2:

Input: 

          1
         /  
        3    
       / \       
      5   3     

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).

Example 3:

Input: 

          1
         / \
        3   2 
       /        
      5      

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).

Example 4:

Input: 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).

Note: Answer will in the range of 32-bit signed integer.
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
 
// Solution I
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int result{0};
        queue<std::pair<TreeNode*, int>> q;
        q.push({root, 1});
        while(!q.empty()){
            int c = q.size();
            if(c == 1){
                q.push({q.front().first, 1});
                q.pop();
            }
            result = max(result, q.back().second - q.front().second + 1);
            while(c-- > 0){
                TreeNode* cur = q.front().first;
                int index = q.front().second;
                q.pop();
                if(cur -> left) q.push({cur -> left, index * 2});
                if(cur -> right) q.push({cur -> right, index * 2 + 1});
            }
            
        }
        return result;
    }
};

//solution II
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        queue<pair<TreeNode*, int>> q;
        int res = 0;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            int first, last;
            int mini=q.front().second;
            for(int i = 0; i < size; i++){
                TreeNode* temp=q.front().first;
                int currid=q.front().second - mini;
                q.pop();
                if(i == 0)
                    first = currid;
                if(i == size - 1)
                    last = currid;
                if(temp -> left)
                    q.push({temp->left,(long long)2 * currid + 1});
                if(temp->right)
                    q.push({temp->right,(long long)2 * currid + 2});
            }
            res = max(res, last - first + 1);
        }
        return res;
    }
};
