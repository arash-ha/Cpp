/*
Power of Four

Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example 1:

Input: 16
Output: true

Example 2:

Input: 5
Output: false

Constraints:

-2^31 <= n <= 2^31 - 1
*/

// Solution I
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num == 0) return false;
        if(num == 1) return true;
        if(num % 4 == 0) return isPowerOfFour(num/4);
        return false;
    }
};

// Solution II
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n < 1)
            return false;
        while(n > 1){
            if (n % 4 != 0) 
                return false;
            n /= 4;
        }
        return true;
    }
};

// Solution III
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(!n)
            return false;
	    while(n % 4 == 0)
            n /= 4;    
	    return n == 1;
    }
};
