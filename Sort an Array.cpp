/*
Sort an Array

Given an array of integers nums, sort the array in ascending order.

 

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
 

Constraints:

1 <= nums.length <= 50000
-50000 <= nums[i] <= 50000
*/

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        quickSort(nums, 0, n-1);
        return nums;
    }
    void quickSort(vector<int>& nums, int low, int high){
        if (low < high){ 
            int pivot = partition(nums, low, high);
            quickSort(nums, low, pivot - 1);
            quickSort(nums, pivot + 1, high);
        }
    }
    int partition (vector<int>& nums, int low, int high){
        int i = (low - 1);
        int pivot = nums[high];
        for (int j = low; j <= high- 1; j++) {
            if (nums[j] <= pivot){
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[high]);
        return (i + 1);
    }
};
