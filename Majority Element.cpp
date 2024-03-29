/*
Majority Element
Given an array of size n, find the majority element. The majority element is the element that appears more than ? n/2 ? times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*/

// Solution I
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), c = 1;
        sort(nums.begin(), nums.end());
        int prev = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] == prev) c++;
            else{
                if(c > n/2) return prev;
                else c = 1;
            }
            prev = nums[i];
        }
        return prev;
    }
};

// Solution II
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> ump;
        for(int n : nums)
            if(++ump[n] > nums.size() / 2)
                return n;
        return 0;
    }
};
