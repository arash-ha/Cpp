/*
Longest Harmonious Subsequence

We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.
Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.
A subsequence of array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.

Example 1:

Input: nums = [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].

Example 2:

Input: nums = [1,2,3,4]
Output: 2

Example 3:

Input: nums = [1,1,1,1]
Output: 0
 
Constraints:

1 <= nums.length <= 2 * 104
-109 <= nums[i] <= 109
*/

// Solution 1
class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = 1;
        int res = 0;
        while(right < nums.size()){
            int diff = nums[right] - nums[left];
            if(diff == 1)
                res = max(res, right - left + 1);
            if(diff <= 1)
                right++;
            else
                left++;
        }
        return res;
    }
};

// Solution 2
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int res = 0, ans;
        map<int, int> mp;
        for(int n : nums)
            mp[n]++;
        for(int i = 0; i < nums.size(); i++){
            if(mp.find(nums[i] + 1) != mp.end())
                ans = mp[nums[i]] + mp[nums[i] + 1];
            res = max(res, ans);
        }
        return res;
    }
};