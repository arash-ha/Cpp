/*
Split Array Largest Sum

Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.
Write an algorithm to minimize the largest sum among these m subarrays.

Example 1:

Input: nums = [7,2,5,10,8], m = 2
Output: 18
Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.

Example 2:

Input: nums = [1,2,3,4,5], m = 2
Output: 9

Example 3:

Input: nums = [1,4,4], m = 3
Output: 4

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 10^6
1 <= m <= min(50, nums.length)
*/

class Solution {
public:
    vector<int> nums;
    int m;
    int splitArray(vector<int>& nums, int m){
        this->nums = nums;
        this->m = m;
        int l = 0, r = 0;
        for(int i = 0; i < nums.size(); i++) l = max(l, nums[i]), r += nums[i];
        int res = r;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(canSplit(mid)){
                res = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return res;
    }
    
    bool canSplit(int largest){
        int subarray = 1, curSum = 0;
        for(auto n : nums){
            curSum += n;
            if(curSum > largest){
                subarray += 1;
                curSum = n;
            }
        }
        return subarray <= m;
    }
};
