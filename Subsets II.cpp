/*
Subsets II
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        backtrack(res, temp, nums, 0);
        return res;
    }
    void backtrack(vector<vector<int>>& res, vector<int>& temp,vector<int>& nums, int index){
        res.emplace_back(temp);
        for(int i = index; i < nums.size(); i++){
            if(i > index && nums[i] == nums[i-1]) continue;
            temp.emplace_back(nums[i]);
            backtrack(res, temp, nums, i + 1);
            temp.pop_back();
        }
    }
};
