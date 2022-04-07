/*
Number of Closed Islands

Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.
Return the number of closed islands.

Example 1:

Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: 
Islands in gray are closed because they are completely surrounded by water (group of 1s).

Example 2:

Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
Output: 1

Example 3:

Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2
 
Constraints:

1 <= grid.length, grid[0].length <= 100
0 <= grid[i][j] <=1
*/

// Solution I
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == 0)
                    if(dfs(grid, i, j))
                        res++;
        return res;
    }
    bool dfs(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || j < 0 || i > grid.size() - 1 || j > grid[0].size() - 1)
            return false;
        if(grid[i][j] == 1)
            return true;
        grid[i][j] = 1;
        bool top = dfs(grid, i + 1, j);
        bool bottom = dfs(grid, i - 1, j);
        bool right = dfs(grid, i, j + 1);
        bool left =  dfs(grid, i, j - 1);
        return top && bottom && right && left;
    }
};

// Solution II
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == 0)
                    if(bfs(grid, i, j))
                        res++;
        return res;
    }
    bool bfs(vector<vector<int>>& grid, int i, int j){
        grid[i][j] = -1;
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        bool flag = true;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x == 0 || x >= grid.size() - 1 || y == 0 || y >= grid[0].size() - 1)
                flag = false;
            if(x - 1 >= 0 && grid[x - 1][y] == 0){
                grid[x - 1][y] = -1;
                q.push(make_pair(x - 1, y));
            }
            if(x + 1 < grid.size() && grid[x + 1][y] == 0){
                grid[x + 1][y] = -1;
                q.push(make_pair(x + 1, y));
            }
            if(y - 1 >= 0 && grid[x][y - 1] == 0){
                grid[x][y - 1] = -1;
                q.push(make_pair(x, y - 1));
            }
            if(y + 1 < grid[0].size() && grid[x][y + 1] == 0){
                grid[x][y + 1] = -1;
                q.push(make_pair(x, y + 1));
            }
        }
        return flag;
    }
};
