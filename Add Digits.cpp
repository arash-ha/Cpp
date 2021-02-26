/*
Add Digits

Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

Example:

Input: 38
Output: 2 
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
Since 2 has only one digit, return it.
*/

// Solution 1
class Solution {
public:
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
};

// Solution 2
class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        while(num > 9){
            while(num > 0){
                sum += num % 10;
                num /= 10;
            }
            num = sum;
            sum = 0;
        }
        return num;
    }
};
