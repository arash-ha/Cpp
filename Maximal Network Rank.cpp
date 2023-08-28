/*
Maximal Network Rank

There is an infrastructure of n cities with some number of roads connecting these cities. Each roads[i] = [ai, bi] indicates that there is a bidirectional road between cities ai and bi.
The network rank of two different cities is defined as the total number of directly connected roads to either city. If a road is directly connected to both cities, it is only counted once.
The maximal network rank of the infrastructure is the maximum network rank of all pairs of different cities.
Given the integer n and the array roads, return the maximal network rank of the entire infrastructure.

Example 1:

Input: n = 4, roads = [[0,1],[0,3],[1,2],[1,3]]
Output: 4
Explanation: The network rank of cities 0 and 1 is 4 as there are 4 roads that are connected to either 0 or 1. The road between 0 and 1 is only counted once.

Example 2:

Input: n = 5, roads = [[0,1],[0,3],[1,2],[1,3],[2,3],[2,4]]
Output: 5
Explanation: There are 5 roads that are connected to cities 1 or 2.

Example 3:

Input: n = 8, roads = [[0,1],[1,2],[2,3],[2,4],[5,6],[5,7]]
Output: 5
Explanation: The network rank of 2 and 5 is 5. Notice that all the cities do not have to be connected.
 
Constraints:

2 <= n <= 100
0 <= roads.length <= n * (n - 1) / 2
roads[i].length == 2
0 <= ai, bi <= n-1
ai != bi
Each pair of cities has at most one road connecting them.
*/
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> cnt(n);
        size_t res = 0, first_max = 0, second_max = 0;
        unordered_set<int> adj;
        for (auto r : roads) {
            ++cnt[r[0]];
            ++cnt[r[1]];
            adj.insert((min(r[0], r[1]) << 16) + max(r[0], r[1]));
        }
        int i_max = max_element(begin(cnt), end(cnt)) - begin(cnt);
        int cnt_max = count(begin(cnt), end(cnt), cnt[i_max]);
        if (cnt_max == 1) {
            for (auto j = 0; j < n; ++j)
                if (i_max != j)
                    res = max(res, cnt[i_max] + cnt[j] - adj.count((min(i_max, j) << 16) + max(i_max, j)));
        }
        else {
            int roads_between_max = count_if(begin(roads), end(roads), [&](vector<int>&r) {
                return cnt[r[0]] == cnt[i_max] && cnt[r[1]] == cnt[i_max];
            });
            res = 2 * cnt[i_max] - (cnt_max * (cnt_max - 1) / 2 > roads_between_max ? 0 : 1);
        }
        return res;
    }
};
