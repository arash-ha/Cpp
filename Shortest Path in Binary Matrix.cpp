/*
Shortest Path in Binary Matrix


In an N by N square grid, each cell is either empty (0) or blocked (1).

A clear path from top-left to bottom-right has length k if and only if it is composed of cells C_1, C_2, ..., C_k such that:

Adjacent cells C_i and C_{i+1} are connected 8-directionally (ie., they are different and share an edge or corner)
C_1 is at location (0, 0) (ie. has value grid[0][0])
C_k is at location (N-1, N-1) (ie. has value grid[N-1][N-1])
If C_i is located at (r, c), then grid[r][c] is empty (ie. grid[r][c] == 0).
Return the length of the shortest such clear path from top-left to bottom-right.  If such a path does not exist, return -1.

Example 1:

Input: [[0,1],[1,0]]
Output: 2

Example 2:

Input: [[0,0,0],[1,1,0],[1,1,0]]
Output: 4

Note:

1 <= grid.length == grid[0].length <= 100
grid[r][c] is 0 or 1
*/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int res = 1;
        int row = grid.size(), col = grid[0].size();
        if (row == 0 || col == 0)
            return -1;
        if (grid[0][0] != 0 || grid[row-1][col-1] != 0)
            return -1;
        queue<pair<int, int>> q;
        q.push(make_pair(0,0));
        vector<vector<int>> directions = {{1, 1}, {0, 1},{1, 0},{0, -1},{-1, 0},{-1, -1},{1, -1},{-1, 1}};
        grid[0][0] = 1;
        while(!q.empty()){
            auto cur = q.front();
            int x = cur.first, y = cur.second;
            if(x == row -1 && y == col -1)
                return grid[x][y];
            for(auto direction : directions){
                int x_1 = x + direction[0];
                int y_1 = y + direction[1];
                if(x_1 >= 0 && x_1 < row && y_1 >= 0 && y_1 < col && grid[x_1][y_1] == 0){
                q.push(make_pair(x_1,y_1));
                grid[x_1][y_1] = grid[x][y] + 1;
            }
        }
        q.pop();
    }
    return -1;
    }
};
