/*
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:

Input: [1,2,3,1]
Output: true
Example 2:

Input: [1,2,3,4]
Output: false
Example 3:

Input: [1,1,1,3,3,4,3,2,4,2]
Output: true
*/


// Solution 1
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int i : nums){
            if(++map[i] > 1) return true;
        }

        return false;
    }
};


// Solution 2
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        bool result{false};
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[j] == nums[i]) result = true;
            }
        }
        return result;
    }
};
