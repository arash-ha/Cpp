/*
Cheapest Flights Within K Stops

There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.
You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

Example 1:

Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.

Example 2:

Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.

Example 3:

Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.
 
Constraints:

1 <= n <= 100
0 <= flights.length <= (n * (n - 1) / 2)
flights[i].length == 3
0 <= fromi, toi < n
fromi != toi
1 <= pricei <= 10^4
There will not be any multiple flights between two cities.
0 <= src, dst, k < n
src != dst

*/
class Solution {
public:
    const int inf = 1e8;
    int dp[101][101];
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        memset(dp, -1, sizeof dp);
        vector<vector<int>> cost(n, vector<int>(n));
        vector<int> adj[n];
        for(auto f : flights){
            adj[f[0]].emplace_back(f[1]);
            cost[f[0]][f[1]] = f[2];
        }
        int res = dfs(src, k + 1, dst, cost, adj);
        return res == inf ? -1 : res;
    }
    int dfs(int node, int k, int dest, vector<vector<int>> &cost, vector<int> adj[]){
        if(k < 0)
            return inf;
        if(node == dest)
            return 0;
        if (dp[node][k] != -1)
            return dp[node][k];
        int res = inf;
        for(auto i : adj[node])
            res = min(res, cost[node][i] + dfs(i, k - 1, dest, cost, adj));
        return dp[node][k] = res;
    }
};
