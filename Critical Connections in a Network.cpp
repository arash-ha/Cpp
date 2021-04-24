/*
Critical Connections in a Network

There are n servers numbered from 0 to n-1 connected by undirected server-to-server connections forming a network where connections[i] = [a, b] represents a connection between servers a and b. Any server can reach any other server directly or indirectly through the network.
A critical connection is a connection that, if removed, will make some server unable to reach some other server.
Return all critical connections in the network in any order.

Example 1:

Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.

Constraints:

1 <= n <= 10^5
n-1 <= connections.length <= 10^5
connections[i][0] != connections[i][1]
There are no repeated connections.
*/

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        for(int i = 0;i < connections.size(); i++){
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int> discovery(n, -1);
        vector<int> low(n, -1);
        vector<int> parent(n, -1);
        vector<vector<int>> bridge;
        for(int i = 0; i < n; i++){
            if(discovery[i] == -1)
                DFS(i, discovery, low, parent, graph, bridge);
        }
        return bridge;
    }
    
    void DFS(int curr,vector<int>& discovery,vector<int>& low,vector<int>& parent,vector<vector<int>>& graph,vector<vector<int>>& bridge){
        
        static int time = 0;
        
        discovery[curr] = time;
        low[curr] = time;
        
        time += 1;
        
        for(auto nbr : graph[curr]){
            
            if(discovery[nbr] == -1){
                parent[nbr] = curr;
                DFS(nbr, discovery, low, parent, graph, bridge);
                low[curr] = min(low[curr], low[nbr]);
                if(low[nbr] > discovery[curr])
                    bridge.push_back({curr,nbr});
            }
            else{
                if(nbr != parent[curr])
                    low[curr] = min(low[curr],discovery[nbr]);
            }
        }
    }
};
