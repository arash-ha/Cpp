/*
Two Sum II - Input array is sorted

Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
 

Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]
Example 3:

Input: numbers = [-1,0], target = -1
Output: [1,2]
 

Constraints:

2 <= nums.length <= 3 * 104
-1000 <= nums[i] <= 1000
nums is sorted in increasing order.
-1000 <= target <= 1000
*/

// Solution I
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while(l < r){
            if(numbers[l] + numbers[r] == target)
                return {l + 1, r + 1};
            else if(numbers[l] + numbers[r] > target)
                r--;
            else
                l++;
        }
        return {};
    }
};

// Solution II
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> ump;
        vector<int> res = {0, 0};
        for(int i = 0; i < numbers.size(); i++){
            int temp = target - numbers[i];
            if(ump.find(temp)!= ump.end()){
                res = {ump[temp] + 1, i + 1};
                break;
            }
            ump[numbers[i]] = i;
        }
        return res;
    }
};
