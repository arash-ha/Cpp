/*
Permutations II
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        set<vector<int>> myset;
        helper(nums, 0, nums.size() - 1, myset);
        for(auto it : myset){
            result.emplace_back(it);
        }
        
        return result;
    }
    
    void helper(vector<int>& nums, int l, int h, set<vector<int>>& myset){
        if(l == h){
            myset.insert(nums);
            return;
        }
        
        else{
            for(int i = l; i <= h; i++){
                swap(nums[l], nums[i]);
                helper(nums, l + 1, h, myset);
                swap(nums[l], nums[i]);
            }
        }
    }
};
