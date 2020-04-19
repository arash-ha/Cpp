/*
 Intersection of Two Arrays
 Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Note:

Each element in the result must be unique.
The result can be in any order.
*/



class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vec{};
        unordered_map<int, int> map;
        for(int i = 0; i < nums1.size(); i++) map[nums1[i]]++;
        for(int j = 0; j < nums2.size(); j++) {
            if(map[nums2[j]] > 0) vec.push_back(nums2[j]); map[nums2[j]] = 0;
        }
        return vec;
    }
};
