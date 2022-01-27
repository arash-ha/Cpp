/*
Maximum XOR of Two Numbers in an Array

Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

Example 1:

Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.

Example 2:

Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127
 
Constraints:

1 <= nums.length <= 2 * 10^5
0 <= nums[i] <= 2^31 - 1
*/

class Solution {
struct TrieNode {
    TrieNode *child[2] = {};
    void increase(int number) {
        TrieNode *cur = this;
        for (int i = 31; i >= 0; --i) {
            int bit = (number >> i) & 1;
            if (cur->child[bit] == nullptr)
                cur->child[bit] = new TrieNode();
            cur = cur->child[bit];
        }
    }
    int findMax(int number) {
        TrieNode *cur = this;
        int res = 0;
        for (int i = 31; i >= 0; --i) {
            int bit = (number >> i) & 1;
            if (cur->child[1 - bit] != nullptr) {
                cur = cur->child[1 - bit];
                res |= (1 << i);
            }
            else cur = cur->child[bit];
        }
        return res;
    }
};
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode *trieNode = new TrieNode();
        for (int x : nums)
            trieNode->increase(x);
        int res = 0;
        for (int x : nums)
            res = max(res, trieNode->findMax(x));
        return res;
    }
};
