/*
Largest Component Size by Common Factor
Given a non-empty array of unique positive integers A, consider the following graph:

There are A.length nodes, labelled A[0] to A[A.length - 1];
There is an edge between A[i] and A[j] if and only if A[i] and A[j] share a common factor greater than 1.
Return the size of the largest connected component in the graph.

 

Example 1:

Input: [4,6,15,35]
Output: 4

Example 2:

Input: [20,50,9,63]
Output: 2

Example 3:

Input: [2,3,6,7,4,12,21,39]
Output: 8

Note:

1 <= A.length <= 20000
1 <= A[i] <= 100000
*/


class Solution {
    int _find (int x, vector<int>& parent){
        if(parent[x]==-1)
            return x;
        parent[x] = _find(parent[x], parent);
        return parent[x];
    }
    
    void _union(int x, int y, vector<int>& parent){
        int xp = _find(x, parent);
        int yp = _find(y, parent);
        if(xp != yp)
            parent[yp] = xp;
    }
public:
    int largestComponentSize(vector<int>& A) {
        vector<int> parent(100001, -1);
        for(int x:A){
            for(int i = 2; i <= sqrt(x); ++i){
                if(x % i == 0){
                    _union(i, x, parent);
                    _union(x, x/i, parent);
                }
            }
        }
        
        int count = 0;
        unordered_map<int, int> ump;
        for(int x:A){
            int xp = _find(x, parent);
            count = max(count, 1 + ump[xp]);
            ump[xp] += 1;
        }
        return count;
    }
};
