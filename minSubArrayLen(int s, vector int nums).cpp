/*
Minimum Size Subarray Sum
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum = s. If there isn't one, return 0 instead.

Example: 

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
*/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0;
        int r = 0;
        int l = 0;
        int result = INT_MAX;
        while(r < nums.size()){
            while(r < nums.size() && sum < s){
                sum += nums[r++];
            }
            while(sum >= s){
                sum -= nums[l++];
            }
            result = min(result, r - l + 1);
        }
        return result <= nums.size() ? result : 0;
    }
};
