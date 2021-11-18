/*
Find All Numbers Disappeared in an Array

Given an array of integers where 1 = a[i] = n (n = size of array), some elements appear twice and others appear once.
Find all the elements of [1, n] inclusive that do not appear in this array.
Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]

Constraints:

n == nums.length
1 <= n <= 10^5
1 <= nums[i] <= n

Follow up: Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
*/

// Solution I
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        if (nums.empty()) return {};
        vector<int> result{};
        for(int num : nums) while(nums[num - 1] != num) swap(num, nums[num - 1]);
        for (int i = 0; i < nums.size(); i++) if (nums [i] != i + 1) result.emplace_back(i + 1);
        return result;
    }
};

// Solution II
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int m = abs(nums[i]) - 1;
            nums[m] = nums[m] > 0 ? -nums[m] : nums[m];
        }
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) res.emplace_back(i + 1);
        }
        return res;
    }
};
