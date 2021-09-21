/*
Distinct Subsequences

Given two strings s and t, return the number of distinct subsequences of s which equals t.
A string's subsequence is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions. (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).
It is guaranteed the answer fits on a 32-bit signed integer.
 
Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from S.
rabbbit
rabbbit
rabbbit

Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from S.
babgbag
babgbag
babgbag
babgbag
babgbag

Constraints:

1 <= s.length, t.length <= 1000
s and t consist of English letters.
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        int tLen = t.length();
        vector<unsigned int> res(tLen + 1, 0);
        res[0] = 1;
        for(auto c : s)
            for(int i = tLen - 1; i >= 0; i--)
                if(c == t[i])
                    res[i + 1] += res[i];
        return res.back();
    }
};
