/*
Combination Sum III
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]
*/

class Solution {

    void dfs(vector<vector<int>>& res, vector<int>& path, int k, int target, int idx){
        if(k == path.size() && target == 0){
            res.push_back(path);
            return;
        }
        for(int i = idx; i <= 9; ++i){
            if(i > target) return;
            path.push_back(i);
            dfs(res, path, k, target - i, i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(res, path, k, n, 1);
        return res;
    }
};

