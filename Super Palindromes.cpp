/*
Super Palindromes

Let's say a positive integer is a super-palindrome if it is a palindrome, and it is also the square of a palindrome.
Given two positive integers left and right represented as strings, return the number of super-palindromes integers in the inclusive range [left, right].

Example 1:

Input: left = "4", right = "1000"
Output: 4
Explanation: 4, 9, 121, and 484 are superpalindromes.
Note that 676 is not a superpalindrome: 26 * 26 = 676, but 26 is not a palindrome.

Example 2:

Input: left = "1", right = "2"
Output: 1 

Constraints:

1 <= left.length, right.length <= 18
left and right consist of only digits.
left and right cannot have leading zeros.
left and right represent integers in the range [1, 1018].
left is less than or equal to right.
*/

class Solution {
    typedef unsigned long long ull;
public:
    bool palindromes(string s) {
        int n = s.size();
        for(int i = 0; i < (n / 2); ++i) {
            if(s[i] != s[n - 1 - i])
                return false;
        }
        return true;
    }
    
    int superpalindromesInRange(string left, string right) {
        ull l = stoull(left), r = stoull(right);
        vector<ull> pal;
        for(int i = 1; i < 10; i++) pal.push_back(i);
        for(int i = 1; i < 10000; i++) {
            string tmp = to_string(i);
            string rev = tmp;
            reverse(rev.begin(), rev.end());
            pal.push_back(stoull(tmp + rev));
            for(int i = 0; i < 10; i++) {
                pal.push_back(stoull(tmp + to_string(i) + rev));
            }
        }
        sort(pal.begin(), pal.end());
        int res = 0;
        for(auto &p : pal) {
            ull val = p * p;
            if(val > r)
                break;
            if(palindromes(to_string(val))) {
                if(val >= l && val <= r)
                    res++;
            }
        }
        return res;
    }
};
