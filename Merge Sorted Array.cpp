/*
Merge Sorted Array

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

The number of elements initialized in nums1 and nums2 are m and n respectively. You may assume that nums1 has enough space (size that is equal to m + n) to hold additional elements from nums2.

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
 
Constraints:

0 <= n, m <= 200
1 <= n + m <= 200
nums1.length == m + n
nums2.length == n
-109 <= nums1[i], nums2[i] <= 109
*/

// Solution 1
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = 0, i = 0, j = 0;
        vector<int> vec(m + n, 0);
        while(k < (m + n)){
            if(i == m){
                while(j < n)
                    vec[k++] = nums2[j++];
                break;
            }
            if(j == n){
                while(i < m)
                    vec[k++] = nums1[i++];
                break;
            }
            if(nums1[i] <= nums2[j])
                vec[k++] = nums1[i++];
            else
                vec[k++] = nums2[j++];
        }
        nums1 = vec;
    }
};

// Solution 2
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while(m > 0 || n > 0){
            if(n <= 0 || m > 0 && nums1[m - 1] > nums2[n - 1])
                nums1[m-- + n - 1] = nums1[m - 1];
            else
                nums1[m + n-- - 1] = nums2[n - 1];
        }
    }
};
