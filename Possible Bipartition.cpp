/*
Possible Bipartition

We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.
Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.

Example 1:

Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4] and group2 [2,3].

Example 2:

Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false

Example 3:

Input: n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
 
Constraints:

1 <= n <= 2000
0 <= dislikes.length <= 10^4
dislikes[i].length == 2
1 <= dislikes[i][j] <= n
ai < bi
All the pairs of dislikes are unique.
*/

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1); 
        vector<int> color(n + 1, 0); 
        vector<bool> explored(n + 1, false); 

        for(auto &edge: dislikes){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
    
        queue<int> q;        
        for(int i = 1; i <= n; ++i) {
            if(!explored[i]){
                color[i] = 1;
                q.push(i);
                while(!q.empty()){
                    int u = q.front();
                    q.pop();
                    if (explored[u]) continue;
                    explored[u] = true;
                    for(auto v: adj[u]){
                        if(color[v] == color[u])
                            return false;
                        color[v] = -color[u];                        
                        q.push(v);
                    }
                }
            }
        }
        
        return true;
    }
};
