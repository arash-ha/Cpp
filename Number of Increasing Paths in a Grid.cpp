/*
Number of Increasing Paths in a Grid

You are given an m x n integer matrix grid, where you can move from a cell to any adjacent cell in all 4 directions.
Return the number of strictly increasing paths in the grid such that you can start from any cell and end at any cell. Since the answer may be very large, return it modulo 109 + 7.
Two paths are considered different if they do not have exactly the same sequence of visited cells.

Example 1:

Input: grid = [[1,1],[3,4]]
Output: 8
Explanation: The strictly increasing paths are:
- Paths with length 1: [1], [1], [3], [4].
- Paths with length 2: [1 -> 3], [1 -> 4], [3 -> 4].
- Paths with length 3: [1 -> 3 -> 4].
The total number of paths is 4 + 3 + 1 = 8.

Example 2:

Input: grid = [[1],[2]]
Output: 3
Explanation: The strictly increasing paths are:
- Paths with length 1: [1], [2].
- Paths with length 2: [1 -> 2].
The total number of paths is 2 + 1 = 3.
 
Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 1000
1 <= m * n <= 10^5
1 <= grid[i][j] <= 10^5
*/
class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        if (m == 1 && n == 1)
            return 1;
        vector<vector<int> > dp(m, vector<int> (n, -1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] == -1)
                  res = (res + helper(grid, i, j, dp, -1)) % 1000000007;
                else
                  res = (res + dp[i][j]) % 1000000007;
            }
        }
        return res;
    }
    int helper(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp, int prev){
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || prev >= grid[i][j])
            return 0;        
        if (dp[i][j] != -1)
            return dp[i][j];        
        int top = helper(grid, i - 1, j, dp, grid[i][j]);
        int bottom = helper(grid, i + 1, j, dp, grid[i][j]);
        int right = helper(grid, i, j + 1, dp, grid[i][j]);
        int left =  helper(grid, i, j - 1, dp, grid[i][j]);
        dp[i][j] = (1 + top + bottom + right + left) % 1000000007;
        return dp[i][j];
    }
};
