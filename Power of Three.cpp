/*
Power of Three

Given an integer, write a function to determine if it is a power of three.

Example 1:

Input: 27
Output: true
Example 2:

Input: 0
Output: false
Example 3:

Input: 9
Output: true
Example 4:

Input: 45
Output: false
*/

//Solution 1
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(!n)
            return false;
	    while(n % 3 == 0)
            n /= 3;    
	    return n == 1;
    }
};

//Solution 2
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 0) return false;
        if(n == 1) return true;
        if(n % 3 == 0) return isPowerOfThree(n/3);
        return false;
    }
};
