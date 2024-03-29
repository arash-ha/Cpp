/*
Perfect Squares

Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.

Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
 
Constraints:

1 <= n <= 10^4
*/

// Solution I
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, n + 1);
        dp[0] = 0, dp[1] = 1;
        for(int i = 2; i <= n; i++){
            for(int k = 1; i - k * k >= 0; k++)
                dp[i] = min(dp[i - k * k] + 1, dp[i]);
        }
        return dp[n];
    }
};

// SOlution II
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 0) return -1;
        else if (num == 0) return 0;
        long mid, low = 0, high = num;
        while(low <= high){
        mid = (low + high)/2;
        if (mid*mid == num) return true;
        else{
            if((mid * mid < num && (mid + 1)*(mid + 1) > num)) return false;
            else if (mid * mid < num)  low = mid + 1;   
            else high = mid - 1;
        }
        }
        return mid;
    }
};
