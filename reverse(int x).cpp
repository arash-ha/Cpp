/*
Reverse Integer
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [-231,  231 - 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

class Solution {
public:
    int class Solution {
public:
    int reverse(int x2) {
        long long x = x2;
        long long rev = 0;
        while(abs(x) > 0){
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        if ((int) rev != rev)
            return 0;
        return rev;
    }
};

