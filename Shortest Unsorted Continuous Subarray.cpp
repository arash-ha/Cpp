/*
Shortest Unsorted Continuous Subarray

Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.
Return the shortest such subarray and output its length.

Example 1:

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

Example 2:

Input: nums = [1,2,3,4]
Output: 0

Example 3:

Input: nums = [1]
Output: 0 

Constraints:

1 <= nums.length <= 104
-105 <= nums[i] <= 105

Follow up: Can you solve it in O(n) time complexity?
*/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int s = -1, e = -1;
        int temp = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(temp > nums[i])
                e = i;
            temp = max(temp, nums[i]);
        }
        temp = nums.back();
        for(int j = nums.size() - 1; j >= 0; j--){
            if(nums[j] > temp)
                s = j;
            temp = min(temp, nums[j]);
        }
        return s == -1 ? 0 : e - s + 1;
    }
};
