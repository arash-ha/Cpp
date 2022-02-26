/*
Nth Magical Number

A positive integer is magical if it is divisible by either a or b.
Given the three integers n, a, and b, return the nth magical number. Since the answer may be very large, return it modulo 109 + 7.

Example 1:

Input: n = 1, a = 2, b = 3
Output: 2

Example 2:

Input: n = 4, a = 2, b = 3
Output: 6

Example 3:

Input: n = 5, a = 2, b = 4
Output: 10

Example 4:

Input: n = 3, a = 6, b = 4
Output: 8
 
Constraints:

1 <= n <= 10^9
2 <= a, b <= 4 * 10^4
*/

class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long lcm = a * b / __gcd(a, b), l = 2, r = 1e14, mod = 1e9 + 7;
        while (l < r) {
            long m = (l + r) / 2;
            if (m / a + m / b - m / lcm < n)
                l = m + 1;
            else
                r = m;
        }
        return l % mod;
    }
};
