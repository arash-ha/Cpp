/*
Valid Palindrome II
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
*/

class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        while(i < j){
            if(s[i] != s[j]){
                return helper(s, i + 1, j) || helper(s, i, j - 1);
            }
            i++;
            j--;
        }
        return true;
    }
    bool helper(string s, int i, int j){
        while(i < j){
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
};
