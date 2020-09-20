/*
Unique Paths II
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?



An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(),  m = obstacleGrid[0].size();
        if(n == 0 || m == 0) return 0;
        vector<vector<long long int>> paths(n, vector<long long int>(m));
        
        int init = 1;
        for(int c = m-1; c >= 0; c--){
            if(obstacleGrid[n-1][c] == 1) init = 0;
            paths[n-1][c] = init;
        }
        
        init = 1;
        for(int r = n-1; r >= 0; r--){
            if(obstacleGrid[r][m-1] == 1) init = 0;
            paths[r][m-1] = init;
        }
        
        for(int r = n-2; r >= 0; r--){
            for(int c = m-2; c >= 0; c--){
                if(obstacleGrid[r][c] == 0)
                    paths[r][c] = paths[r][c+1] + paths[r+1][c];
            }
        }
        return paths[0][0];
    }
};
