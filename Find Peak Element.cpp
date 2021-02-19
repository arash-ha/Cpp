/*
Find Peak Element

A peak element is an element that is strictly greater than its neighbors.
Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
You may imagine that nums[-1] = nums[n] = -8.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
 
Constraints:

1 <= nums.length <= 1000
-231 <= nums[i] <= 231 - 1
nums[i] != nums[i + 1] for all valid i.
*/

//Solution 1
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        nums.insert(nums.begin(), INT_MIN);
        nums.emplace_back(INT_MIN);
        int peak = nums[1], res = 0;
        for(int i = 1; i < nums.size() - 1; i++){
            if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1]){
                if(nums[i] > peak){
                    peak = nums[i];
                    res = i - 1;
                }
                    
            }
        }
        return res;
    }
};

// Solution 2
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while(low < high - 1){
            int mid = (low + high) / 2;
            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) 
                return mid;
            else if(nums[mid] > nums[mid + 1]) 
                    high = mid - 1;
                 else 
                    low = mid + 1;    
        }
        return nums[low] > nums[high] ? low : high;
    }
};
