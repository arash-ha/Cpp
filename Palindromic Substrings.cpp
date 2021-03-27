/*
Palindromic Substrings


Given a string, your task is to count how many palindromic substrings in this string.
The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
 
Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 
Note:

The input string length won't exceed 1000.
*/

class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<int>> memo(s.size(), vector<int>(s.size(), -1));
        int c = 0;
        for(int i = 0; i < s.size(); i++)
            for(int j = i; j < s.size(); j++)
                c += helper(memo, s, i, j);
        return c;
    }
    
    int helper(vector<vector<int>>& memo, string s, int i, int j){
        if (i >= j)
            return 1;
        if(memo[i][j] >= 0)
            return memo[i][j];
        return memo[i][j] = s[i] == s[j] ? helper(memo, s, i + 1, j - 1) : 0;
    }
};
