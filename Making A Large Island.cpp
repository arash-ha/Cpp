/*
Making A Large Island

You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
Return the size of the largest island in grid after applying this operation.
An island is a 4-directionally connected group of 1s.

Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.

Example 2:

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.

Example 3:

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.
 
Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 500
grid[i][j] is either 0 or 1.
*/

class Solution {
    int dirs[5] = {-1, 0, 1, 0, -1};
public:
    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int, int>sizes;
        int m = grid.size(), n = grid[0].size(), curId = 2, res = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] != 1)
                    continue;
                queue<int> q{{i * n + j}};
                int cnt = 0;
                while(!q.empty()){
                    int len = q.size();
                    for(int k = 0; k < len; ++k){
                        int x = q.front() / n, y = q.front() % n;
                        q.pop();
                        if(grid[x][y] == curId)
                            continue;
                        cnt++;
                        grid[x][y] = curId;
                        for(int l = 0; l < 4; ++l){
                            int nx = dirs[l] + x, ny = dirs[l + 1] + y;
                            if(nx < 0 ||ny < 0 ||nx >= m ||ny >= n ||grid[nx][ny] != 1)
                                continue;
                            q.push(nx * n + ny);
                        }
                    }
                }
                sizes[curId++] = cnt;
                res = max(res, cnt);
            }
        }
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 0){
                    set<int> s;
                    for(int k = 0; k < 4; ++k){
                        int x = i + dirs[k], y = j + dirs[k + 1];
                        if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0)
                            continue;
                        s.insert(grid[x][y]);
                    }
                    int sum = 1;
                    for(auto &it : s)
                        sum += sizes[it];
                    res = max(res, sum);
                }
            }
        }
        return res;
    }
};
