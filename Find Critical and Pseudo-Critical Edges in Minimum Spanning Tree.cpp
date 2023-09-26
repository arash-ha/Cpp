/*
Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree

Given a weighted undirected connected graph with n vertices numbered from 0 to n - 1, and an array edges where edges[i] = [ai, bi, weighti] represents a bidirectional and weighted edge between nodes ai and bi. A minimum spanning tree (MST) is a subset of the graph's edges that connects all vertices without cycles and with the minimum possible total edge weight.
Find all the critical and pseudo-critical edges in the given graph's minimum spanning tree (MST). An MST edge whose deletion from the graph would cause the MST weight to increase is called a critical edge. On the other hand, a pseudo-critical edge is that which can appear in some MSTs but not all.
Note that you can return the indices of the edges in any order.

Example 1:

Input: n = 5, edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
Output: [[0,1],[2,3,4,5]]
Explanation: The figure above describes the graph.
The following figure shows all the possible MSTs:
Notice that the two edges 0 and 1 appear in all MSTs, therefore they are critical edges, so we return them in the first list of the output.
The edges 2, 3, 4, and 5 are only part of some MSTs, therefore they are considered pseudo-critical edges. We add them to the second list of the output.

Example 2:

Input: n = 4, edges = [[0,1,1],[1,2,1],[2,3,1],[0,3,1]]
Output: [[],[0,1,2,3]]
Explanation: We can observe that since all 4 edges have equal weight, choosing any 3 edges from the given 4 will yield an MST. Therefore all 4 edges are pseudo-critical.
 
Constraints:

2 <= n <= 100
1 <= edges.length <= min(200, n * (n - 1) / 2)
edges[i].length == 3
0 <= ai < bi < n
1 <= weighti <= 1000
All pairs (ai, bi) are distinct.
*/
class UnionFind {
public: 
    vector<int> parent; 
    UnionFind(int n){
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i; 
    }
    
    int findParent(int p) {
        return parent[p] == p ? p : parent[p] = findParent(parent[p]); 
    }
    
    void Union(int u , int v) {
        int pu = findParent(u) , pv = findParent(v); 
        parent[pu] = pv;
    }    
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<int> critical ,  pscritical ;
        for (int i = 0; i < edges.size(); i++)
            edges[i].push_back(i); 
        sort(edges.begin() , edges.end() , cmp) ;
        int mstwt = findMST(n,edges,-1,-1); //3
        for (int i = 0; i < edges.size(); i++) {
            if (mstwt< findMST(n, edges, i, -1))
                critical.push_back(edges[i][3]); 
            else if (mstwt == findMST(n, edges, -1, i))
                pscritical.push_back(edges[i][3]);
        }
        return {critical , pscritical};         
    }

    static bool cmp(vector<int>&a , vector<int>&b) {
        return a[2] < b[2]; 
    }

    int findMST(int &n ,  vector<vector<int>>& edges , int block , int e) {
        UnionFind uf(n); 
        int weight = 0 ;
        if (e != -1) {
            weight += edges[e][2]; 
            uf.Union(edges[e][0] , edges[e][1]); 
        }
        for (int i = 0; i < edges.size(); i++){
            if (i == block) 
                continue; 
            if (uf.findParent(edges[i][0]) == uf.findParent(edges[i][1]))
                continue; 
            uf.Union(edges[i][0] , edges[i][1]); 
            weight += edges[i][2]; 
        } 
        for (int i = 0; i < n; i++){
            if (uf.findParent(i) != uf.findParent(0))
                return INT_MAX;
        }    
        return weight; 
    }
};
