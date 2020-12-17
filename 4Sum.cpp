/*
4Sum

Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Notice that the solution set must not contain duplicate quadruplets.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [], target = 0
Output: []
 

Constraints:

0 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(nums, temp, res, target, 0, 0, 0);
        return res;
    }
    void backtrack(const vector<int> nums, vector<int> temp, vector<vector<int>>& res, const int target, int sum, int count, int index){
        if(count == 4){
            if(sum == target)
                res.emplace_back(temp);
            return;
        }
        for(int i = index; i < nums.size(); i++){
            if(i != index && nums[i] == nums[i - 1])
                continue;
            if(sum + nums[i] + (3 - count)*nums[nums.size() - 1] < target)
                continue;
            if(sum + (4 - count)*nums[i] > target)
                break;
            temp.emplace_back(nums[i]);
            backtrack(nums, temp, res, target, sum + nums[i], count + 1, i + 1);
            temp.pop_back();
        }
    }
};
