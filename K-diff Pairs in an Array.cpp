/*
K-diff Pairs in an Array

Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.
A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:
0 <= i, j < nums.length
i != j
a <= b
b - a == k
 
Example 1:

Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.

Example 2:

Input: nums = [1,2,3,4,5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).

Example 3:

Input: nums = [1,3,1,5,4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).

Example 4:

Input: nums = [1,2,4,4,3,3,0,9,2,3], k = 3
Output: 2

Example 5:

Input: nums = [-1,-2,-3], k = 1
Output: 2
 
Constraints:

1 <= nums.length <= 10^4
-10^7 <= nums[i] <= 10^7
0 <= k <= 10^7
*/

// Solution I
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        set<pair<int, int>> s; 
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(binary_search(nums.begin()+i+1, nums.end(), nums[i] + k) > 0){
                s.insert(make_pair(nums[i], nums[i] + k));
            }
        }
        return s.size();
    }
};

// Solutioin II

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0, i = 0, j = 1, n = nums.size();
        while(i < n && j < n){
            if(i == j || nums[j] - nums[i] < k)
                j++;
            else{
                if(nums[j] - nums[i] == k){
                    res++;
                    j++;
                    for(; j < n; j++)
                        if(nums[j] != nums[j - 1])
                            break;
                    if(j == n)
                        return res;
                    j--;
                }
                i++;
                while(i < j && nums[i] == nums[i - 1])
                    i++;
            }
        }
        return res;
    }
};
