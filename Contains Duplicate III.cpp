/*
Contains Duplicate III

Solution
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3, t = 0
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1, t = 2
Output: true
Example 3:

Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false
*/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        set<int> set(nums.begin(), nums.end());
        if(t ==0 && n == set.size()) return false;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < i+1+k; j++){
                if(j >= n) break;
                if(abs((long long)nums[i] - nums[j]) <= t) return true;
            }
        }
        return false;
    }
};
