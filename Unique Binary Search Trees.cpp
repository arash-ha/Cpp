/*
Unique Binary Search Trees

Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

Example 1:

Input: n = 3
Output: 5

Example 2:

Input: n = 1
Output: 1
 
Constraints:

1 <= n <= 19
*/

// Solution I
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= i; j++)
                dp[i] += dp[j - 1] * dp[i - j];
        return dp[n];
    }
};

// Solution II

class Solution {
public:
    int numTrees(int n) {
        return helper(1, n);
    }
    int helper(int low, int high){
        if(low >= high)
            return 1;
        int res = 0;
        for(int i = low; i <= high; i++)
            res += helper(low, i - 1) * helper(i + 1, high);
        return res;
    }
};
