/*
Permutations
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        set<vector<int>> myset;
        helper(nums, 0, nums.size() - 1, result);

        return result;
    }
    
    void helper(vector<int>& nums, int l, int h, vector<vector<int>>& result){
        if(l == h){
            result.emplace_back(nums);
            return;
        }
        
        else{
            for(int i = l; i <= h; i++){
                swap(nums[l], nums[i]);
                helper(nums, l + 1, h, result);
                swap(nums[l], nums[i]);
            }
        }
    }
};
