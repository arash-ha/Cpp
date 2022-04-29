/*
Min Cost to Connect All Points

You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.
Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

Example 1:

Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation: 
We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.

Example 2:

Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18
 
Constraints:

1 <= points.length <= 1000
-10^6 <= xi, yi <= 10^6
All pairs (xi, yi) are distinct.
*/

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), res = 0, i = 0, connected = 0;
        vector<int> min_d(n, 10000000);
        while(++connected < n){
            min_d[i] = INT_MAX;
            int min_j = i;
            for(int j = 0; j < n; ++j)
                if(min_d[j] != INT_MAX){
                    min_d[j] = min(min_d[j], abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]));
                    min_j = min_d[j] < min_d[min_j] ? j : min_j;
                }
            res += min_d[min_j];
            i = min_j;
        }
        return res;
    }
};
