/* 
Ugly Number

Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.

Example 1:

Input: n = 6
Output: true
Explanation: 6 = 2 × 3

Example 2:

Input: n = 1
Output: true
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.

Example 3:

Input: n = 14
Output: false
Explanation: 14 is not ugly since it includes the prime factor 7.
 
Constraints:

-2^31 <= n <= 2^31 - 1
*/


class Solution {
public:
    bool isUgly(int num) {
        if(num == 0) return false;
        if(num == 1) return true;
        if(num % 2 == 0) return isUgly(num/2);
        if(num % 3 == 0) return isUgly(num/3);
        if(num % 5 == 0) return isUgly(num/5);
        return false;
    }
};
