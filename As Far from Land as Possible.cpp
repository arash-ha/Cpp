/*
As Far from Land as Possible

Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.
The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

Example 1:

Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
Output: 2
Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.

Example 2:

Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
Output: 4
Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.
 
Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 100
grid[i][j] is 0 or 1
*/

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();   
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == 1) q.push({i,j});
        int  res = 0;
        while(!q.empty()){
            int temp_i = q.front().first;
            int temp_j = q.front().second;
            q.pop();
            vector<pair<int,int>>dir = {{0,1},{0,-1},{1,0},{-1,0}};
            for(auto &it : dir){
                int new_i = it.first + temp_i;
                int new_j = it.second + temp_j;
                if(new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && grid[new_i][new_j] == 0){                    
                    q.push({new_i,new_j});
                    grid[new_i][new_j] = grid[temp_i][temp_j] + 1;
                    res = max(res, grid[new_i][new_j]);
                }
            }
        }
        return res - 1;
    }
};
