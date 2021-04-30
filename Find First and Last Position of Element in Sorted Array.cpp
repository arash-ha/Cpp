/*
Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
Follow up: Could you write an algorithm with O(log n) runtime complexity?

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 
Constraints:

0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
nums is a non-decreasing array.
-10^9 <= target <= 10^9
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2);
        int n = nums.size() - 1;
        res[0] = binarySearch(nums, 0, n, target, false);
        res[1] = binarySearch(nums, 0, n, target, true);
        return res;
    }
    int binarySearch(vector<int> & nums,int l,int h,int target,bool b){
        int res = -1;
        while(l <= h){
            int mid = (l + h) / 2;          
            if(nums[mid] == target){
                res = mid;
                if(b)
                    l = mid + 1;
                else
                    h = mid - 1;
            }
            else if(nums[mid] > target)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return res;
    }
};
