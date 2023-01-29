/*
Max Points on a Line

Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.

Example 1:

Input: points = [[1,1],[2,2],[3,3]]
Output: 3

Example 2:

Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
 
Constraints:

1 <= points.length <= 300
points[i].length == 2
-10^4 <= xi, yi <= 10^4
All the points are unique.
*/

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n < 3)
            return n;
        int res = 2;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int cur = 2;
                for(int k = 0; k < n; k++){
                    if(k != i && k != j){
                        if((points[j][1] - points[i][1]) * (points[i][0] - points[k][0]) == (points[i][1] - points[k][1]) * (points[j][0] - points[i][0]))
                            cur++;
                    }
                }
                res = max(res, cur);
            }
        }
        return res;
    }
};
