/*
Erect the Fence

You are given an array trees where trees[i] = [xi, yi] represents the location of a tree in the garden.
You are asked to fence the entire garden using the minimum length of rope as it is expensive. The garden is well fenced only if all the trees are enclosed.
Return the coordinates of trees that are exactly located on the fence perimeter.

Example 1:

Input: points = [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
Output: [[1,1],[2,0],[3,3],[2,4],[4,2]]

Example 2:

Input: points = [[1,2],[2,2],[4,2]]
Output: [[4,2],[2,2],[1,2]]
 
Constraints:

1 <= points.length <= 3000
points[i].length == 2
0 <= xi, yi <= 100
All the given points are unique.

*/

class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        vector<vector<int>> res;
        sort(trees.begin(), trees.end(), mycompare);
        for(int i = 0; i < n; i++) {
            while(res.size() > 1 && orientation(res[res.size()-2], res.back(), trees[i]) < 0) 
                res.pop_back();
            res.push_back(trees[i]);
        }
        if(res.size() == n)
            return res;
        for(int i = n - 2; i >= 0; i--){
            while(res.size() > 1 && orientation(res[res.size() - 2], res.back(), trees[i]) < 0) 
                res.pop_back();
            res.push_back(trees[i]);
        }
        res.pop_back();
        return res;
    }
    static bool mycompare(vector<int>& a, vector<int>& b) {
        return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
    }
    int orientation(vector<int>& a, vector<int>& b, vector<int>& c) {
        return (b[0] - a[0])*(c[1] - b[1]) - (b[1] - a[1])*(c[0] - b[0]);
    }
};
