/*
Convert a Number to Hexadecimal

Given an integer num, return a string representing its hexadecimal representation. For negative integers, two’s complement method is used.
All the letters in the answer string should be lowercase characters, and there should not be any leading zeros in the answer except for the zero itself.

Example 1:

Input: num = 26
Output: "1a"

Example 2:

Input: num = -1
Output: "ffffffff"
 
Constraints:

-2^31 <= num <= 2^31 - 1
*/


class Solution {
public:
    string toHex(int num) {
        if(num == 0)
            return "0";
        const string mp = "0123456789abcdef";
        string ans;
        int i = 0;
        while(num && i++ < 8){
            ans = mp[(num & 15)] + ans;
            num >>= 4;
        }
        return ans;
    }
};
