/*
Maximum Length of Repeated Subarray

Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

Example 1:

Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].

Example 2:

Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
Output: 5
 
Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 100
*/

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), res = 0;
        if(n > m)
            return findLength(nums2, nums1);
        vector<int> dp(n + 1), temp(n + 1);
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(nums1[i - 1] == nums2[j - 1])
                    dp[j] = temp[j - 1] + 1;
                else
                    dp[j] = 0;
                res = max(res, dp[j]);
            }
            dp.swap(temp);
        }
        return res;
    }
};
