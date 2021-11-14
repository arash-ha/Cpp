/*
Top K Frequent Elements

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:

Input: nums = [1], k = 1
Output: [1]

Constraints:

1 <= nums.length <= 10^5
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 
Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res(k);
        unordered_map<int, int> ump;
        for(auto n : nums)
            ump[n]++;
        vector<pair<int, int>> vec{};
        for(auto e : ump)
            vec.emplace_back(e);
        sort(vec.begin(), vec.end(), comp);
        for(int i = 0; i < k; i++)
            res[i] = vec[i].first;
        return res;
    }
    static bool comp(pair<int, int>& a, pair<int, int>& b){
        return a.second > b.second;
    }
};
