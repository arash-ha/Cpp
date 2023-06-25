/*
Stone Game II

Alice and Bob continue their games with piles of stones.  There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].  The objective of the game is to end with the most stones. 
Alice and Bob take turns, with Alice starting first.  Initially, M = 1.
On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M.  Then, we set M = max(M, X).
The game continues until all the stones have been taken.
Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.

Example 1:

Input: piles = [2,7,9,4,4]
Output: 10
Explanation:  If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 piles in total. If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 piles in total. So we return 10 since it's larger. 

Example 2:

Input: piles = [1,2,3,4,5,100]
Output: 104
 
Constraints:

1 <= piles.length <= 100
1 <= piles[i] <= 10^4
*/
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        vector<vector<int>> dp(piles.size(), vector<int>(piles.size(), 0));
        vector<int> sum(piles.size() + 1, 0);
        for (int i = piles.size() - 1; i >= 0; i--)
            sum[i] = sum[i + 1] + piles[i];
        return helper(dp, 1, 0, sum);
    }
    
    int helper(vector<vector<int>>& dp, int m, int pos, vector<int>& sum) {
        if (pos + 2 * m >= sum.size() - 1)
            return sum[pos]; 
        int res = 0;
        for (int i = 1; i <= 2 * m; i++) {
            int s = sum[pos] - sum[i + pos];
            if (dp[i + pos][max(i, m)]==0)
                dp[i + pos][max(i, m)] = helper(dp, max(i, m), i + pos, sum);
            res = max(res, s + sum[i + pos] - dp[i + pos][max(i, m)]);
        }
        return res;
    }
};
