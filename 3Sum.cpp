/*
3Sum

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []
 

Constraints:

0 <= nums.length <= 3000
-105 <= nums[i] <= 105

*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
            return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < n - 1; i++){
            if(i != 0 && nums[i] == nums[i-1])
                continue;
            int low = i + 1, high = n-1;
            while(low < high){
                int sum = nums[i] + nums[low] + nums[high];
                if(sum == 0){
                    res.push_back({nums[i], nums[low], nums[high]});
                    int left = nums[low];
                    while(low < high && left == nums[low])
                        low++;
                    int right = nums[high];
                    while(low < high && right == nums[high])
                        high--;
                }
                else if(sum > 0)
                    high--;
                else
                    low++;
            }
        }
        return res;
    }
};
