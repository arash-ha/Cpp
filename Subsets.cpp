/*
Subsets
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
*/


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        backtrack(res, temp, nums, 0);
        return res;
    }
    void backtrack(vector<vector<int>>& res, vector<int>& temp,vector<int>& nums, int index){
        res.emplace_back(temp);
        for(int i = index; i < nums.size(); i++){
            temp.emplace_back(nums[i]);
            backtrack(res, temp, nums, i + 1);
            temp.pop_back();
        }
    }
};
