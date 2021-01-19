/*
Longest Palindromic Substring

Given a string s, return the longest palindromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:

Input: s = "cbbd"
Output: "bb"

Example 3:

Input: s = "a"
Output: "a"

Example 4:

Input: s = "ac"
Output: "a"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters (lower-case and/or upper-case),
*/

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() <= 1)
            return s;
        int max_len = 1, n = s.length(), st = 0, end = 0;
        // Odd length
        for(int i = 0; i < n - 1; i++)
            getPalindromeLength(s, i, i, st, end, max_len, n);
        
        // Even length
        for(int i = 0; i < n - 1; i++)
            getPalindromeLength(s, i, i + 1, st, end, max_len, n);
        
        return s.substr(st, max_len);
    }
    void getPalindromeLength(const string s, int l, int r, int& st, int& end, int& max_len, const int n){
        while(l >= 0 && r < n){
            if(s[l] == s[r]){
                l--;
                r++;
            }
            else
                break;
        }
        int len = r - l - 1;
        if(len > max_len){
            max_len = len;
            st = l + 1;
            end = r - 1;
        }
    }
};


 
