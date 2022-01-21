/*
Partition to K Equal Sum Subsets

Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.

Example 1:

Input: nums = [4,3,2,3,5,2,1], k = 4
Output: true
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.

Example 2:

Input: nums = [1,2,3,4], k = 3
Output: false
 
Constraints:

1 <= k <= nums.length <= 16
1 <= nums[i] <= 10^4
The frequency of each element is in the range [1, 4].
*/

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(auto n : nums)
            sum += n;
        if(k <= 0 || sum % k != 0)
            return false;
        vector<int> seen(nums.size(), 0);
        return helper(nums, seen, 0, k, 0, 0, sum / k);
    }
    
    bool helper(vector<int>& nums, vector<int>& seen, int start_index, int k, int cur_sum, int cur_num, int target){
        if(k==1)return true;
        if(cur_sum == target && cur_num >0 )
            return helper(nums, seen, 0, k-1, 0, 0, target);
        for(int i = start_index; i<nums.size(); i++){
            if(!seen[i]){
                seen[i] = 1;
                if(helper(nums, seen, i+1, k, cur_sum + nums[i], cur_num++, target))
                    return true;
                seen[i] = 0;
            }
        }
        return false;
    }
};
