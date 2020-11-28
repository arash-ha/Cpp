/*
Partition Equal Subset Sum


Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
*/


// Solution 1
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0), target = sum >> 1;
        if (sum & 1) return false;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for(auto num : nums) 
            for(int i = target; i >= num; i--)
                dp[i] = dp[i] || dp[i - num];
        return dp[target];
    }
};

// Solution 2

class Solution {
    bool helper(vector<int>& nums, int i, int ssum, vector<vector<bool>> dp){
        if(ssum == 0)
            return true;
        if(ssum < 0)
            return false;
        if(i >= nums.size())
            return false;
        if(dp[i][ssum] == NULL)
            dp[i][ssum] = helper(nums, i + 1, ssum - nums[i], dp) || helper(nums, i + 1, ssum, dp);
        return dp[i][ssum];
    }
    
    
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<bool>> dp(nums.size() + 1, vector<bool> (totalSum/2 + 1));
        return totalSum % 2 == 1 ? false : helper(nums, 0, totalSum / 2, dp);
    }
};
