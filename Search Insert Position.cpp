/*
Search Insert Position

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2

Example 2:

Input: [1,3,5,6], 2
Output: 1

Example 3:

Input: [1,3,5,6], 7
Output: 4

Example 4:

Input: [1,3,5,6], 0
Output: 0
*/
// Solution I

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};

// Solution II
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index;
        if (target == 0) return 0;
        for (int i = 0; i < nums.size(); i++){
            if (target <= nums[i]){
                index = i;
                break;
            }
            index = nums.size();
        }
        return index;
    }
};

