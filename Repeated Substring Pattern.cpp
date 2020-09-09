/*
Repeated Substring Pattern
Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

 

Example 1:

Input: "abab"
Output: True
Explanation: It's the substring "ab" twice.
Example 2:

Input: "aba"
Output: False
Example 3:

Input: "abcabcabcabc"
Output: True
Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
*/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for(int i = n/2; i > 0; i--){
            if(n % i == 0){
                int j = 0;
                while(j + i < n && s[j] == s[j + i]) j++;
                if(j + i == n) return true;
            }
        }
        return false;
    }
};
