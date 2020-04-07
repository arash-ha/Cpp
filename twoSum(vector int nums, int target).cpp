/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

// Solution 1
#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result {};
        unordered_map<int, int> h;
        for (int i = 0; i < nums.size(); i++){\
            int n2 = target - nums[i];
            if (h.find(n2) != h.end() && i != h[n2]){
                result.emplace_back(h[n2]);
                result.emplace_back(i);
                return result;
            }
        h[nums[i]] = i;

        }
        
        return result;
    }
};

// Solution 2
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result {};

        for (int i = 0; i < nums.size() - 1; i++){
            for(int j = 1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target && i != j){
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
};

