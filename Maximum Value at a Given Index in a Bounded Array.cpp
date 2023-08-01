/*
Maximum Value at a Given Index in a Bounded Array

You are given three positive integers: n, index, and maxSum. You want to construct an array nums (0-indexed) that satisfies the following conditions:
nums.length == n
nums[i] is a positive integer where 0 <= i < n.
abs(nums[i] - nums[i+1]) <= 1 where 0 <= i < n-1.
The sum of all the elements of nums does not exceed maxSum.
nums[index] is maximized.
Return nums[index] of the constructed array.

Note that abs(x) equals x if x >= 0, and -x otherwise. 

Example 1:

Input: n = 4, index = 2,  maxSum = 6
Output: 2
Explanation: nums = [1,2,2,1] is one array that satisfies all the conditions.
There are no arrays that satisfy all the conditions and have nums[2] == 3, so 2 is the maximum nums[2].

Example 2:

Input: n = 6, index = 1,  maxSum = 10
Output: 3
 
Constraints:

1 <= n <= maxSum <= 10^9
0 <= index < n
*/

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        maxSum -= n;
        int left = 0, right = maxSum, mid;
        while (left < right) {
            mid = (left + right + 1) / 2;
            if (test(n, index, mid) <= maxSum)
                left = mid;
            else
                right = mid - 1;
        }
        return left + 1;
    }

    long test(int n, int index, int a) {
        int b = max(a - index, 0);
        long res = long(a + b) * (a - b + 1) / 2;
        b = max(a - ((n - 1) - index), 0);
        res += long(a + b) * (a - b + 1) / 2;
        return res - a;
    }
};
