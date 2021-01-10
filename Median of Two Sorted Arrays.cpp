/*
Median of Two Sorted Arrays

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

Follow up: The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000
Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000
Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size();
        if(size % 2 == 0){
            int left = helper(nums1, 0, nums2, 0, size / 2);
            int right = helper(nums1, 0, nums2, 0, size / 2 + 1);
            return (left + right) / 2.0;
        }
        else
            return helper(nums1, 0, nums2, 0, size / 2 + 1);
    }
    
    int helper(vector<int>& nums1, int i, vector<int>& nums2, int j, int k){
        if(nums1.size() - i > nums2.size() - j)
            return helper(nums2, j ,nums1, i, k);
        if(nums1.size() == i)
            return nums2[j + k - 1];
        if(k == 1)
            return min(nums1[i], nums2[j]);
        int ii = min(i + k / 2, int(nums1.size())), jj = j + k / 2;
        if(nums1[ii - 1] > nums2[jj - 1])
            return helper(nums1, i, nums2, j + k / 2, k - k / 2);
        else
            return helper(nums1, ii, nums2, j, k - (ii - i));
    }
};
