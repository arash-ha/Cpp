/*
Maximum Score from Performing Multiplication Operations

You are given two integer arrays nums and multipliers of size n and m respectively, where n >= m. The arrays are 1-indexed.
You begin with a score of 0. You want to perform exactly m operations. On the ith operation (1-indexed), you will:
Choose one integer x from either the start or the end of the array nums.
Add multipliers[i] * x to your score.
Remove x from the array nums.
Return the maximum score after performing m operations.

Example 1:

Input: nums = [1,2,3], multipliers = [3,2,1]
Output: 14
Explanation: An optimal solution is as follows:
- Choose from the end, [1,2,3], adding 3 * 3 = 9 to the score.
- Choose from the end, [1,2], adding 2 * 2 = 4 to the score.
- Choose from the end, [1], adding 1 * 1 = 1 to the score.
The total score is 9 + 4 + 1 = 14.

Example 2:

Input: nums = [-5,-3,-3,-2,7,1], multipliers = [-10,-5,3,4,6]
Output: 102
Explanation: An optimal solution is as follows:
- Choose from the start, [-5,-3,-3,-2,7,1], adding -5 * -10 = 50 to the score.
- Choose from the start, [-3,-3,-2,7,1], adding -3 * -5 = 15 to the score.
- Choose from the start, [-3,-2,7,1], adding -3 * 3 = -9 to the score.
- Choose from the end, [-2,7,1], adding 1 * 4 = 4 to the score.
- Choose from the end, [-2,7], adding 7 * 6 = 42 to the score. 
The total score is 50 + 15 - 9 + 4 + 42 = 102.
 
Constraints:

n == nums.length
m == multipliers.length
1 <= m <= 10^3
m <= n <= 10^5
-1000 <= nums[i], multipliers[i] <= 1000
*/

class Solution {
public:
    vector<vector<int>> dp;
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size();
        dp.resize(m + 1, vector<int> (m + 1, INT_MIN));
        return solve(0, 0, nums, multipliers);
    }
    int solve(int i, int j, vector<int>& nums, vector<int>& multipliers){
        if(dp[i][j] != INT_MIN)
            return dp[i][j];
        int n = nums.size();
        if(j == multipliers.size())
            return 0;
        int left = solve(i + 1, j + 1, nums, multipliers) + (nums[i] * multipliers[j]);
        int right = solve(i, j + 1, nums, multipliers) + (nums[n - 1 - j + i] * multipliers[j]);
        return dp[i][j] = max(left, right);
    }
};
