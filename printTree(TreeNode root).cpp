/*
Print Binary Tree
Print a binary tree in an m*n 2D string array following these rules:

The row number m should be equal to the height of the given binary tree.
The column number n should always be an odd number.
The root node's value (in string format) should be put in the exactly middle of the first row it can be put. The column and the row where the root node belongs will separate the rest space into two parts (left-bottom part and right-bottom part). You should print the left subtree in the left-bottom part and print the right subtree in the right-bottom part. The left-bottom part and the right-bottom part should have the same size. Even if one subtree is none while the other is not, you don't need to print anything for the none subtree but still need to leave the space as large as that for the other subtree. However, if two subtrees are none, then you don't need to leave space for both of them.
Each unused space should contain an empty string "".
Print the subtrees following the same rules.
Example 1:
Input:
     1
    /
   2
Output:
[["", "1", ""],
 ["2", "", ""]]
Example 2:
Input:
     1
    / \
   2   3
    \
     4
Output:
[["", "", "", "1", "", "", ""],
 ["", "2", "", "", "", "3", ""],
 ["", "", "4", "", "", "", ""]]
Example 3:
Input:
      1
     / \
    2   5
   / 
  3 
 / 
4 
Output:

[["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
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
    vector<vector<string>> printTree(TreeNode* root) {
        queue<TreeNode*> Q;
        Q.push(root);
        int row{0}, col{0};
        while(!Q.empty()){
            int size = Q.size();
            while(size > 0){
                TreeNode* cur = Q.front();
                Q.pop();
                if(cur -> left) Q.push(cur -> left);
                if(cur -> right) Q.push(cur -> right);
                size --;
            }
            row++;
            col = col * 2 + 1;
        }
        vector<vector<string>> result(row, vector<string>(col, ""));
        helper(result, root, 0, 0, col - 1);
        return result;
    }
    
    void helper(vector<vector<string>>& result, TreeNode* root, int row, int s, int e){
        if(!root) return;
        int mid = (s + e)/2;
        result[row][mid] = to_string(root -> val);
        helper(result, root -> left, row + 1, s, mid - 1);
        helper(result, root -> right, row + 1, mid + 1, e);
    }
    
};
