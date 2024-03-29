/*
Power of Two

Given an integer, write a function to determine if it is a power of two.

Example 1:

Input: 1
Output: true 
Explanation: 20 = 1

Example 2:

Input: 16
Output: true
Explanation: 24 = 16

Example 3:

Input: 218
Output: false

Constraints:

-2^31 <= n <= 2^31 - 1
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0)
            return false;
        if(n == 1)
            return true;
        if(n > 1){
            if(ceil(log2(n)) == floor(log2(n))){
                return true;
            }
        }
        return false;
    }
};
