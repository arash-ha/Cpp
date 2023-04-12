/*
Largest Color Value in a Directed Graph

There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.
You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.
A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.
Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.

Example 1:

Input: colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
Output: 3
Explanation: The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are colored "a" (red in the above image).

Example 2:

Input: colors = "a", edges = [[0,0]]
Output: -1
Explanation: There is a cycle from 0 to 0.
 
Constraints:

n == colors.length
m == edges.length
1 <= n <= 10^5
0 <= m <= 10^5
colors consists of lowercase English letters.
0 <= aj, bj < n
*/
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        vector<vector<int>> al(colors.size()), cnt(colors.size(), vector<int>(26));
        vector<int> visited(colors.size());
        for(auto &e : edges)
            al[e[0]].push_back(e[1]);
        int res = 0;
        for(auto i = 0; i < colors.size() && res != INT_MAX; ++i)
            res = max(res, dfs(i, colors, al, cnt, visited));
        return res == INT_MAX ? -1 : res;
    }
    int dfs(int i, string &c, vector<vector<int>> &al, vector<vector<int>> &cnt, vector<int> &visited){
        if(!visited[i]){
            visited[i] = 1;
            for(auto j : al[i]){
                if(dfs(j, c, al, cnt, visited) == INT_MAX)
                    return INT_MAX;
                for(auto k = 0; k < 26; ++k)
                    cnt[i][k] = max(cnt[i][k], cnt[j][k]);
            }
            cnt[i][c[i] - 'a']++;
            visited[i] = 2;
        }
        return visited[i] == 2 ? cnt[i][c[i] - 'a'] : INT_MAX;
    }
};
