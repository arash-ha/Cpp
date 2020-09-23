/*
Majority Element II
Given an integer array of size n, find all elements that appear more than ? n/3 ? times.

Note: The algorithm should run in linear time and in O(1) space.

Example 1:

Input: [3,2,3]
Output: [3]
Example 2:

Input: [1,1,1,3,3,2,2,2]
Output: [1,2]
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(), cap = n/3, c = 1;
        if(n == 0) return nums;
        sort(nums.begin(), nums.end());
        vector<int> res;
        int prev = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] == prev) c++;
            else{
                if(c > cap) res.emplace_back(prev);
                c = 1;
            }
            prev = nums[i];
        }
        if(find(res.begin(), res.end(), prev) == res.end() && c > cap) res.emplace_back(prev);
        return res;
    }
};
