/*
Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:

Input: n = 1
Output: ["()"]
 
Constraints:

1 <= n <= 8
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(res, "", 0, n, n);
        return res;
    }
    void helper(vector<string> &res, string cur, int c, int left, int right){
        if(c < 0)
            return;
        if(!left && !right){
            res.emplace_back(cur);
            return;
        }
        if(left)
            helper(res, cur + "(", c + 1, left - 1, right);
        if(right)
            helper(res, cur + ")", c - 1, left, right - 1);
    }
};
