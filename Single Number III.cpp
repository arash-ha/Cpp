/*
Single Number III

Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.
Follow up: Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.

Example 2:

Input: nums = [-1,0]
Output: [-1,0]

Example 3:

Input: nums = [0,1]
Output: [1,0]
 
Constraints:

2 <= nums.length <= 3 * 10^4
-231 <= nums[i] <= 2^31 - 1
Each integer in nums will appear twice, only two integers will appear once.
*/

// Solution 1
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        for(int i = 0; i < nums.size();){
            if(i == nums.size() - 1 || nums[i] != nums[i+1]){
                res.emplace_back(nums[i]);
                i++;
            }
            else
                i += 2;
        }
        return res;
    }
};

// Solution 2

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> ump;
        for(auto n : nums)
            ump[n]++;
        for(auto it = ump.begin(); it != ump.end(); it++){
            if(it -> second == 1)
                res.emplace_back(it -> first);
        }
        return res;
    }
};
