/*
Is Subsequence

Given a string s and a string t, check if s is subsequence of t.
You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).
A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:

s = "abc", t = "ahbgdc"
Return true.

Example 2:

s = "axc", t = "ahbgdc"
Return false.


Constraints:

0 <= s.length <= 100
0 <= t.length <= 10^4
s and t consist only of lowercase English letters.

Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k >= 109, and you want to check one by one to see if t has its subsequence. In this scenario, how would you change your code?*/

// Solution I
class Solution {
public:
    bool isSubsequence(string s, string t) {
        bool k{true};
        int idx{0};
        int cur = string::npos;
        for(auto & i : s ){
            if((cur = t.find(i, idx)) < idx) k = false;
            else idx = cur + 1;
        }       
        return k;
    }
};

// Solution II
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_size = s.size(), t_size = t.size();
        int count = 0;
        for(int i = 0, j = 0; i < t_size; i++){
            if(t[i] == s[j]){ 
                j++;
                count++;
            }
        }
        return count == s_size;
    }
};
