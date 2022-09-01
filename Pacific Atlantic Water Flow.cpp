/*
Pacific Atlantic Water Flow

There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.
The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).
The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.
Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

Example 1:

Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
[0,4]: [0,4] -> Pacific Ocean 
       [0,4] -> Atlantic Ocean
[1,3]: [1,3] -> [0,3] -> Pacific Ocean 
       [1,3] -> [1,4] -> Atlantic Ocean
[1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean 
       [1,4] -> Atlantic Ocean
[2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean 
       [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
[3,0]: [3,0] -> Pacific Ocean 
       [3,0] -> [4,0] -> Atlantic Ocean
[3,1]: [3,1] -> [3,0] -> Pacific Ocean 
       [3,1] -> [4,1] -> Atlantic Ocean
[4,0]: [4,0] -> Pacific Ocean 
       [4,0] -> Atlantic Ocean
Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.

Example 2:

Input: heights = [[1]]
Output: [[0,0]]
Explanation: The water can flow from the only cell to the Pacific and Atlantic oceans.
 
Constraints:

m == heights.length
n == heights[r].length
1 <= m, n <= 200
0 <= heights[r][c] <= 10^5
*/

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> visited(m, vector<int> (n, 0));
        vector<vector<int>> res;
        if(heights.empty())
            return res;
        for(int i = 0; i < m; i++){
            dfs(heights, i, 0, INT_MIN, 1, visited, res);
            dfs(heights, i, n - 1, INT_MIN, 2, visited, res);
            }
        for(int j = 0; j < n; j++){
            dfs(heights, 0, j, INT_MIN, 1, visited, res);
            dfs(heights, m - 1, j, INT_MIN, 2, visited, res);
        }
        return res;
    }

    void dfs(vector<vector<int>>& heights, int x, int y, int preh, int prev, vector<vector<int>>& visited, vector<vector<int>>& res){
        if(x < 0 || x >= heights.size() || y < 0 || y >= heights[0].size() || heights[x][y] < preh || (visited[x][y] & prev) == prev)
            return;
        visited[x][y] |= prev;
        if(visited[x][y] == 3)
            res.push_back({x, y});
        dfs(heights, x + 1, y, heights[x][y], visited[x][y], visited, res);
        dfs(heights, x - 1, y, heights[x][y], visited[x][y], visited, res);
        dfs(heights, x, y + 1, heights[x][y], visited[x][y], visited, res);
        dfs(heights, x, y - 1, heights[x][y], visited[x][y], visited, res);
    }
};
